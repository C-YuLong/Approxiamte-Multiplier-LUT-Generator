import os

# 定义多个输入路径
folder_paths = [
    './References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned',
    # 添加更多路径，例如：
    './References/AAM'
]

output_cpp = './src/multipliers.hpp'
info_path = './info/Added_References_LUT_info.txt'

include_lines = []
MAE_call_lines = []
func_names = []  # 用于保存所有的func_name

# 计算输出目录的绝对路径
output_dir = os.path.abspath(os.path.dirname(output_cpp))

# 初始化MAE调用行（只添加一次头部）
MAE_call_lines.append(
    '{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::trunc);'
    'outFile << "Multiplier,WeightedMAE" << "\\n";'
    'outFile.close(); }\n'
)

# 遍历所有目标文件夹
for folder in folder_paths:
    folder_abs = os.path.abspath(folder)
    # 计算相对于输出目录的路径
    relative_to_output = os.path.relpath(folder_abs, output_dir)
    
    # 遍历当前文件夹中的文件
    for filename in os.listdir(folder):
        if filename.endswith('.c'):
            func_name = os.path.splitext(filename)[0]
            # 生成相对于输出目录的包含路径
            include_path = os.path.join(relative_to_output, filename).replace('\\', '/')
            
            # 添加到include_lines
            include_lines.append(f'#include "{include_path}"  // {func_name} function\n')
            
            # 生成MAE调用行
            MAE_call_lines.append(
                '{{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);'
                'outFile << "{0}," << calculateWeightedMAE(probX, probY, {0}) << "\\n";'
                'outFile.close(); }}\n'.format(func_name)
            )
            
            # 添加到函数名列表
            func_names.append(func_name)

# 生成LUT调用行
LUT_call_lines = []
for func_name in func_names:
    LUT_call_lines.append(f'\tgenerateMultiplicationTable({func_name}, "{func_name}");\n')

# 输出到C++文件
with open(output_cpp, 'w') as file:
    file.write('#include <fstream>\n')
    file.write('#include <iostream>\n')
    file.write('#include "ReadFunction.hpp"\n\n')
    file.writelines(include_lines)
    
    # 写入MAE写入函数
    file.write('\nvoid writeMAEToCSV(const std::array<double, 256>& probX, const std::array<double, 256>& probY) {\n')
    file.writelines(MAE_call_lines)
    file.write('}\n')
    
    # 写入LUT生成函数
    file.write('\nvoid GenerateLUT() {\n')
    file.writelines(LUT_call_lines)
    file.write('}\n')

# 将func_names写入info文件
with open(info_path, 'w') as info_file:
    info_file.write('\n'.join(func_names))

print(f'C++ header file has been written to {output_cpp}')
print(f'Function names have been written to {info_path}')