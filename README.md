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



`./src`下存放源文件

`MAE main.cpp`：主函数文件

`multipliers.hpp`：自动生成的include文件，包含了全部的近似乘法器

`ReadFunction.hpp`：主要函数功能实现文件

`ExtractFunction.py`：自动生成`multipliers.hpp`的文件，可以读取指定路径下的所有hpp文件并生成对应的`multipliers.hpp`