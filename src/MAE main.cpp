#include "multipliers.hpp"

#include <string>

using namespace std;

void GenerateWeightedMAE(){
    string filePathX = "../Weights/model_weights_distribution.txt";
    string filePathY = "../Image/mnist_pixel_distribution.txt";

    auto probX = loadDistribution(filePathX);
    auto probY = loadDistribution(filePathY);
    writeMAEToCSV(probX, probY);
}

int main(){
    GenerateWeightedMAE();
    GenerateLUT();
    return 0;
}

