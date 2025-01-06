import os
import pandas as pd

def read_multiplier_from_csv(file_path):
    """从 CSV 文件读取 'Multiplier' 列，忽略空格并返回集合"""
    df = pd.read_csv(file_path)
    if 'Multiplier' in df.columns:
        return set(df['Multiplier'].str.replace(' ', '', regex=True).unique())  # 去除空格
    return set()

def read_multipliers_from_txt(folder_path):
    """读取文件夹下所有 TXT 文件的文件名（去掉 .txt 后缀），并去除空格"""
    txt_files = [os.path.splitext(f)[0] for f in os.listdir(folder_path) if f.endswith('.txt')]
    return set([name.replace(' ', '') for name in txt_files])  # 去除空格

def read_multipliers_from_all_csv_in_directory(folder_path):
    """读取文件夹下所有 CSV 文件中的 'Multiplier' 列数据，并合并"""
    multipliers = set()
    for filename in os.listdir(folder_path):
        if filename.endswith('.csv'):
            file_path = os.path.join(folder_path, filename)
            multipliers.update(read_multiplier_from_csv(file_path))
    return multipliers

# 读取数据
pda_file_path = './PDA/pda.csv'
multiplier_folder_path = './MultiplierLUT'
weighted_mae_folder_path = './WeightedMAE'

# 获取三个列表的 Multiplier 数据
pda_multipliers = read_multiplier_from_csv(pda_file_path)
multiplier_multipliers = read_multipliers_from_txt(multiplier_folder_path)
weighted_mae_multipliers = read_multipliers_from_all_csv_in_directory(weighted_mae_folder_path)

# 比较三个集合
all_multipliers = pda_multipliers | multiplier_multipliers | weighted_mae_multipliers  # 所有的 Multiplier
# 找到完全匹配的乘法器（三个集合都有的）
common_all = pda_multipliers & multiplier_multipliers & weighted_mae_multipliers

# 输出缺失的名字和缺少的文件夹
for multiplier in all_multipliers:
    missing_folders = []
    if multiplier not in pda_multipliers:
        missing_folders.append('PDA')
    if multiplier not in multiplier_multipliers:
        missing_folders.append('MultiplierLUT')
    if multiplier not in weighted_mae_multipliers:
        missing_folders.append('WeightedMAE')

    if missing_folders:
        print(f"{multiplier} is missing in: {', '.join(missing_folders)}")

print(f"真值表LUT 权重MAE 硬件PDA完全匹配的乘法器: {common_all}")
