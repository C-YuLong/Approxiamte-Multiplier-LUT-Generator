import os
import pandas as pd
import re

def clean_string(s):
    """去除字符串中的空格和制表符"""
    return re.sub(r'[\s\t]', '', s)

def read_fine_txt(file_path):
    """从 fine.txt 文件读取每一行的乘法器名称"""
    with open(file_path, 'r') as file:
        multipliers = [clean_string(line.strip()) for line in file.readlines()]
    return multipliers

def get_weighted_mae_for_multiplier_from_csv(folder_path, multiplier):
    """在给定文件夹下的所有 CSV 文件中查找对应乘法器的 WeightedMAE"""
    for filename in os.listdir(folder_path):
        if filename.endswith('.csv'):
            file_path = os.path.join(folder_path, filename)
            df = pd.read_csv(file_path)
            if 'Multiplier' in df.columns and 'WeightedMAE' in df.columns:
                # 清理乘法器名称中的空格和制表符
                df['Multiplier_cleaned'] = df['Multiplier'].apply(clean_string)
                # 找到乘法器对应的 WeightedMAE
                matching_row = df[df['Multiplier_cleaned'] == multiplier]
                if not matching_row.empty:
                    return matching_row['WeightedMAE'].values[0]
    return None

def get_pda_values_for_multiplier(file_path, multiplier):
    """从 pda.csv 文件中获取与乘法器对应的值"""
    df = pd.read_csv(file_path)
    # 清理乘法器名称中的空格和制表符
    df['Multiplier_cleaned'] = df['Multiplier'].apply(clean_string)
    matching_row = df[df['Multiplier_cleaned'] == multiplier]
    if not matching_row.empty:
        # 获取对应的多个值
        total_cell_area = matching_row['Total cell area(um^2)'].values[0]
        data_arrival_time = matching_row['slack'].values[0]
        slack_total_power = matching_row['Total power'].values[0]
        return total_cell_area, data_arrival_time, slack_total_power
    return None, None, None

def calculate_and_sort_multipliers(fine_txt_path, weighted_mae_folder_path, pda_file_path, multiplier_lut_path, teld_lut_path):
    """计算每个乘法器的乘积并排序，记录不符合条件的乘法器，更新 TELD-LUT 文件"""
    multipliers = read_fine_txt(fine_txt_path)
    results = []
    excluded_multipliers = []  # 用于记录被排除的乘法器及原因

    for multiplier in multipliers:
        # 获取 WeightedMAE
        weighted_mae = get_weighted_mae_for_multiplier_from_csv(weighted_mae_folder_path, multiplier)
        if weighted_mae is None:
            excluded_multipliers.append((multiplier, 'Missing in WeightedMAE data'))
            continue

        # 获取 PDA 中的对应值
        total_cell_area, data_arrival_time, slack_total_power = get_pda_values_for_multiplier(pda_file_path, multiplier)
        if total_cell_area is None or data_arrival_time is None or slack_total_power is None:
            excluded_multipliers.append((multiplier, 'Missing in PDA data'))
            continue
        
        # 检查是否符合过滤条件
        if weighted_mae > 50 or total_cell_area >= 100 or slack_total_power >= 100:
            excluded_multipliers.append((multiplier, 'Does not meet filter criteria'))
            continue
        
        # 计算乘积
        product = weighted_mae * total_cell_area * data_arrival_time * slack_total_power
        results.append((multiplier, product))

        # 读取 MultiplierLUT 中的对应 .txt 文件
        lut_file_path = os.path.join(multiplier_lut_path, f"{multiplier}.txt")
        if os.path.exists(lut_file_path):
            with open(lut_file_path, 'r') as lut_file:
                lut_content = lut_file.readlines()

            # 创建 TELD-LUT 目录，如果不存在
            if not os.path.exists(teld_lut_path):
                os.makedirs(teld_lut_path)

            # 将计算的乘积值写入文件的第一行
            teld_lut_file_path = os.path.join(teld_lut_path, f"{multiplier}.txt")
            with open(teld_lut_file_path, 'w') as teld_file:
                teld_file.write(f"{product}\n")  # 写入乘积值
                teld_file.writelines(lut_content)  # 追加原始 LUT 内容

    # 根据乘积排序
    sorted_results = sorted(results, key=lambda x: x[1], reverse=True)

    # 输出排序结果到终端
    print("\nSorted Multipliers by Product:")
    for multiplier, product in sorted_results:
        print(f"{multiplier}: {product}")

    # 输出被排除的乘法器及原因
    if excluded_multipliers:
        print("\nExcluded Multipliers (and the reason):")
        for multiplier, reason in excluded_multipliers:
            print(f"{multiplier}: {reason}")

# 文件路径
fine_txt_path = './info/fine.txt'
weighted_mae_folder_path = './WeightedMAE'
pda_file_path = './PDA/pda.csv'
multiplier_lut_path = './MultiplierLUT'
teld_lut_path = './TLED-LUT'

# 执行计算和排序
calculate_and_sort_multipliers(fine_txt_path, weighted_mae_folder_path, pda_file_path, multiplier_lut_path, teld_lut_path)
