import os

folder_path = './References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned'
output_cpp = './multipliers.hpp'
info_path = '../info/LUT_info.txt'

include_lines = []
MAE_call_lines = []
func_names = []  # 用于保存所有的func_name

# 遍历目标文件夹
for filename in os.listdir(folder_path):
    if filename.endswith('.c'):
        func_name = os.path.splitext(filename)[0]
        real_path = '.' + folder_path + '/' + filename
        include_lines.append(f'#include "{real_path}"  // {func_name} function\n')
        # 修改call_lines来生成C++代码片段
        MAE_call_lines.append(f'{{ std::ofstream outFile("results.csv", std::ios::app); outFile << "{func_name}," << calculateWeightedMAE(probX, probY, {func_name}) << "\\n"; outFile.close(); }}\n')
        func_names.append(func_name)  # 保存func_name到列表

LUT_call_lines = []
for filename in os.listdir(folder_path):
    if filename.endswith('.c'):
        func_name = os.path.splitext(filename)[0]
        LUT_call_lines.append(f'\tgenerateMultiplicationTable({func_name}, "{func_name}");\n')

# 输出到C++文件
with open(output_cpp, 'w') as file:
    file.write('#include <fstream>\n')  # 包含必要的头文件
    file.write('#include <iostream>\n')
    file.write('#include "ReadFunction.hpp"\n')  # 包含自定义的头文件
    file.writelines(include_lines)
    file.write('\nvoid writeMAEToCSV(const std::array<double, 256>& probX, const std::array<double, 256>& probY) {\n')
    file.writelines(MAE_call_lines)
    file.write('}\n')
    file.write('\nvoid GenerateLUT() {\n')
    file.writelines(LUT_call_lines)
    file.write('}\n')

# 将func_names写入info_path文件
with open(info_path, 'w') as info_file:
    for func_name in func_names:
        info_file.write(f'{func_name}\n')

print(f'C++ output has been written to {output_cpp}')
print(f'Function names have been written to {info_path}')
