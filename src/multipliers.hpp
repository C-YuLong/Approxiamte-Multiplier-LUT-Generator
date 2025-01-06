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

void writeMAEToCSV(const std::array<double, 256>& probX, const std::array<double, 256>& probY) {
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "Multiplier, WeightedMAE" << "\n"; outFile.close(); }
 { std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_13QR," << calculateWeightedMAE(probX, probY, mul8u_13QR) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_150Q," << calculateWeightedMAE(probX, probY, mul8u_150Q) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_185Q," << calculateWeightedMAE(probX, probY, mul8u_185Q) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_1JFF," << calculateWeightedMAE(probX, probY, mul8u_1JFF) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_2AC," << calculateWeightedMAE(probX, probY, mul8u_2AC) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_E9R," << calculateWeightedMAE(probX, probY, mul8u_E9R) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_FTA," << calculateWeightedMAE(probX, probY, mul8u_FTA) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_LM7," << calculateWeightedMAE(probX, probY, mul8u_LM7) << "\n"; outFile.close(); }
{ std::ofstream outFile("../WeightedMAE/WeightedMAEResults.csv", std::ios::app); outFile << "mul8u_Y48," << calculateWeightedMAE(probX, probY, mul8u_Y48) << "\n"; outFile.close(); }
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
}
