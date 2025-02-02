#include <iostream>
#include <cstdint>
#include <cmath> // For abs
#include <fstream>
#include <string>
#include <array>
#include <functional> // For function
#include <numeric>

using namespace std;


// 定义函数指针类型，用于接受符合特定签名的任何函数
using FuncPtr = uint64_t(*)(uint64_t, uint64_t);

uint64_t my_abs(uint64_t x){
    return x > 0 ? x : -x;
}

// 计算MAE的模板函数
uint32_t calculateMAE(FuncPtr func) {
    uint64_t totalError = 0;
    int count = 0;

    for (uint16_t x = 0; x <= 255; ++x) {
        for (uint16_t y = 0; y <= 255; ++y) {
            // 精确乘法结果
            uint64_t exactProduct = x * y;
            // 调用传入的函数计算近似乘法结果
            uint64_t approxProduct = func(static_cast<uint64_t>(x), static_cast<uint64_t>(y));
            // 累计误差
            totalError += my_abs(exactProduct - approxProduct);
            ++count;
        }
    }

    // 计算平均绝对误差
    return totalError / count;
}

array<double, 256> loadDistribution(const string& filePath) {
    array<double, 256> distribution{};
    distribution.fill(0); // 初始化数组

    ifstream file(filePath);
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(':');
        if (pos != string::npos) {
            int pixelValue = stoi(line.substr(0, pos));
            double count = stod(line.substr(pos + 1));
            distribution[pixelValue] = count;
        }
    }

    // 转换计数为概率
    double total = accumulate(distribution.begin(), distribution.end(), 0.0);
    for (auto& value : distribution) {
        value /= total;
    }

    return distribution;
}

double calculateWeightedMAE(const array<double, 256>& probX, const array<double, 256>& probY, FuncPtr approxMul) {
    double weightedTotalError = 0.0;
    double totalWeight = 0.0;

    for (int x = 0; x < 256; ++x) {
        for (int y = 0; y < 256; ++y) {
            uint16_t pReal = static_cast<uint16_t>(x) * static_cast<uint16_t>(y);
            uint16_t pApprox = approxMul(static_cast<uint8_t>(x), static_cast<uint8_t>(y));
            uint16_t error = abs(static_cast<int>(pReal) - static_cast<int>(pApprox));
            double weightX = probX[x];
            double weightY = probY[y];
            double weightedError = error * weightX * weightY;
            weightedTotalError += weightedError;
            totalWeight += weightX * weightY;
        }
    }

    return weightedTotalError / totalWeight;
}

void generateMultiplicationTable(FuncPtr approxMul, const string& name) {
    // 构建文件路径
    string filePath = "../MultiplierLUT/" + name + ".txt";
    
    // 打开文件
    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    // 使用approxMul函数来计算并写入乘法表
    for (uint16_t i = 0; i <= 255; ++i) {
        for (uint16_t j = 0; j <= 255; ++j) {
            // 计算乘法结果
            uint16_t result = approxMul(static_cast<uint8_t>(i), static_cast<uint8_t>(j));
            outFile << static_cast<unsigned>(result);
            if (j < 255) {
                outFile << " ";
            }
        }
        outFile << "\n";
    }

    outFile.close();
    cout << "Multiplication table has been saved to " << filePath << endl;
}