#include <fstream>
#include <iostream>
#include "ReadFunction.hpp"

#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_13QR.c"  // mul8u_13QR function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_150Q.c"  // mul8u_150Q function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_185Q.c"  // mul8u_185Q function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_1JFF.c"  // mul8u_1JFF function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_2AC.c"  // mul8u_2AC function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_E9R.c"  // mul8u_E9R function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_FTA.c"  // mul8u_FTA function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_LM7.c"  // mul8u_LM7 function
#include "../References/evoapproxlib-master/selected_multipliers/pareto_pwr_mae 8_8 unsigned/mul8u_Y48.c"  // mul8u_Y48 function
#include "../References/AAM/VGG16_XFYW_1.c"  // VGG16_XFYW_1 function
#include "../References/AAM/VGG16_XFYW_2.c"  // VGG16_XFYW_2 function
#include "../References/AAM/VGG16_XFYW_3.c"  // VGG16_XFYW_3 function
#include "../References/AAM/VGG16_XFYW_4.c"  // VGG16_XFYW_4 function
#include "../References/AAM/VGG16_XFYW_5.c"  // VGG16_XFYW_5 function
#include "../References/AAM/VGG16_XFYW_6.c"  // VGG16_XFYW_6 function
#include "../References/AAM/VGG16_XFYW_7.c"  // VGG16_XFYW_7 function
#include "../References/AAM/VGG16_XFYW_8.c"  // VGG16_XFYW_8 function
#include "../References/AAM/VGG16_XFYW_9.c"  // VGG16_XFYW_9 function

void writeMAEToCSV(const std::array<double, 256>& probX, const std::array<double, 256>& probY) {
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::trunc);outFile << "Multiplier,WeightedMAE" << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_13QR," << calculateWeightedMAE(probX, probY, mul8u_13QR) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_150Q," << calculateWeightedMAE(probX, probY, mul8u_150Q) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_185Q," << calculateWeightedMAE(probX, probY, mul8u_185Q) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_1JFF," << calculateWeightedMAE(probX, probY, mul8u_1JFF) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_2AC," << calculateWeightedMAE(probX, probY, mul8u_2AC) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_E9R," << calculateWeightedMAE(probX, probY, mul8u_E9R) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_FTA," << calculateWeightedMAE(probX, probY, mul8u_FTA) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_LM7," << calculateWeightedMAE(probX, probY, mul8u_LM7) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "mul8u_Y48," << calculateWeightedMAE(probX, probY, mul8u_Y48) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_1," << calculateWeightedMAE(probX, probY, VGG16_XFYW_1) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_2," << calculateWeightedMAE(probX, probY, VGG16_XFYW_2) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_3," << calculateWeightedMAE(probX, probY, VGG16_XFYW_3) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_4," << calculateWeightedMAE(probX, probY, VGG16_XFYW_4) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_5," << calculateWeightedMAE(probX, probY, VGG16_XFYW_5) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_6," << calculateWeightedMAE(probX, probY, VGG16_XFYW_6) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_7," << calculateWeightedMAE(probX, probY, VGG16_XFYW_7) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_8," << calculateWeightedMAE(probX, probY, VGG16_XFYW_8) << "\n";outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app);outFile << "VGG16_XFYW_9," << calculateWeightedMAE(probX, probY, VGG16_XFYW_9) << "\n";outFile.close(); }
}

void GenerateLUT() {
	generateMultiplicationTable(mul8u_13QR, "mul8u_13QR");
	generateMultiplicationTable(mul8u_150Q, "mul8u_150Q");
	generateMultiplicationTable(mul8u_185Q, "mul8u_185Q");
	generateMultiplicationTable(mul8u_1JFF, "mul8u_1JFF");
	generateMultiplicationTable(mul8u_2AC, "mul8u_2AC");
	generateMultiplicationTable(mul8u_E9R, "mul8u_E9R");
	generateMultiplicationTable(mul8u_FTA, "mul8u_FTA");
	generateMultiplicationTable(mul8u_LM7, "mul8u_LM7");
	generateMultiplicationTable(mul8u_Y48, "mul8u_Y48");
	generateMultiplicationTable(VGG16_XFYW_1, "VGG16_XFYW_1");
	generateMultiplicationTable(VGG16_XFYW_2, "VGG16_XFYW_2");
	generateMultiplicationTable(VGG16_XFYW_3, "VGG16_XFYW_3");
	generateMultiplicationTable(VGG16_XFYW_4, "VGG16_XFYW_4");
	generateMultiplicationTable(VGG16_XFYW_5, "VGG16_XFYW_5");
	generateMultiplicationTable(VGG16_XFYW_6, "VGG16_XFYW_6");
	generateMultiplicationTable(VGG16_XFYW_7, "VGG16_XFYW_7");
	generateMultiplicationTable(VGG16_XFYW_8, "VGG16_XFYW_8");
	generateMultiplicationTable(VGG16_XFYW_9, "VGG16_XFYW_9");
}
