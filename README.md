# 近似乘法器生成工具

本项目旨在对对应的近似乘法器进行指标(metrics)的计算和LUT的生成。

适用乘法器：**8*8近似乘法器**

计算指标：$PDA * (1+MAE)$

（*此处的MAE指的是带有分布的MAE*）



`./MultiplierLUT`中存储的是生成的乘法器的LUT文件

`./PDA`中需要放入一个csv文件`pda.csv`，内部存储需要筛选的乘法器的PDA值

`./Image`中存放图像的输入分布

`./Weights`中存放权重的输入分布

`./References`中存放获得的近似乘法器

`./info`中存放核对信息

`./info/Checkinfo.py` 中比较是否同时具有PDA、WeightedMAE和LUT生成。



`./src`下存放源文件

`./src/MAE main.cpp`：主函数文件

`./src/multipliers.hpp`：自动生成的include文件，包含了全部的近似乘法器

`./src/ReadFunction.hpp`：主要函数功能实现文件

`./src/ExtractFunction.py`：自动生成`multipliers.hpp`的文件，可以读取指定路径下的所有hpp文件并生成对应的`multipliers.hpp`

`./src/ProcessLUT.py`：对LUT进行信息标注



python文件使用vscode打开文件为基准

C++文件使用自己为基准





使用方法：

1. 将获得的乘法器的hpp文件放入Reference中
2. 在`ExtractFunction.py`中进行路径的修改，生成`multipliers.hpp`文件
3. 运行`MAE main.cpp`生成权重MAE和LUT文件
4. 把额外自己原有的LUT文件和PDA文件放入`./MultilplierLUT`和`./PDA/pda.csv`中
5. 把额外原有的权重MAE值放入`./WeightedMAE`中（注意：不能用空格和`\t`，列名必须是`Multiplier`和`WeightedMAE`）
6. 在`./info/check_info.py`中检查哪些乘法器没有完整的配置。并同时生成记录完整数据的乘法器列表`fine.txt`