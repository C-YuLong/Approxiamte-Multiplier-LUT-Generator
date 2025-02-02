import os
import pandas as pd
import re
import math
import matplotlib.pyplot as plt

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
        # product = weighted_mae * math.log(total_cell_area * data_arrival_time * slack_total_power)
        product = math.log(weighted_mae * total_cell_area * data_arrival_time * slack_total_power)
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

def calculate_and_plot_mae_vs_pda_with_filter(fine_txt_path, weighted_mae_folder_path, pda_file_path):
    """根据MAE和PDA的过滤条件计算每个乘法器的乘积，并绘制横轴为MAE，纵轴为ln(PDA)的散点图，并标注乘法器名称"""
    multipliers = read_fine_txt(fine_txt_path)  # 读取乘法器列表
    mae_values = []  # 存储 MAE 值
    pda_ln_values = []  # 存储 PDA 自然对数的值
    multiplier_names = []  # 存储乘法器名称
    excluded_multipliers = []  # 用于记录排除的乘法器及原因

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
        
        # 过滤条件：如果不满足条件，则跳过
        if weighted_mae > 50 or total_cell_area >= 100 or slack_total_power >= 100 or data_arrival_time >= 5:
            excluded_multipliers.append((multiplier, 'Does not meet filter criteria'))
            continue
        
        # 计算 PDA 的自然对数
        pda_value = total_cell_area * data_arrival_time * slack_total_power
        if pda_value > 0:  # 确保 PDA 值大于 0，才能计算其自然对数
            pda_ln = math.log(pda_value)
            # pda_ln = pda_value
        else:
            excluded_multipliers.append((multiplier, 'Invalid PDA value'))
            continue

        # 将符合条件的乘法器的 MAE 和 ln(PDA) 添加到列表中
        mae_values.append(weighted_mae)
        pda_ln_values.append(pda_ln)
        multiplier_names.append(multiplier)  # 添加乘法器名称

    # 绘制 MAE vs ln(PDA) 散点图
    plt.figure(figsize=(10, 6))
    plt.scatter(mae_values, pda_ln_values, color='b', label='Multipliers')

    # 为每个点添加标注
    for i, multiplier in enumerate(multiplier_names):
        plt.annotate(multiplier, (mae_values[i], pda_ln_values[i]), textcoords="offset points", xytext=(0, 5), ha='center')

    plt.title('Scatter plot of MAE vs ln(PDA)')
    plt.xlabel('MAE (Weighted MAE)')
    plt.ylabel('ln(PDA)')

    # 显示排除的乘法器及原因
    if excluded_multipliers:
        print("\nExcluded Multipliers (and the reason):")
        for multiplier, reason in excluded_multipliers:
            print(f"{multiplier}: {reason}")

    plt.grid(True)
    plt.show()

# 文件路径
fine_txt_path = './info/fine.txt'
weighted_mae_folder_path = './WeightedMAE'
pda_file_path = './PDA/pda.csv'
multiplier_lut_path = './MultiplierLUT'
teld_lut_path = './TLED-LUT'

# 执行计算和排序
calculate_and_sort_multipliers(fine_txt_path, weighted_mae_folder_path, pda_file_path, multiplier_lut_path, teld_lut_path)
# calculate_and_plot_mae_vs_pda_with_filter(fine_txt_path, weighted_mae_folder_path, pda_file_path)
