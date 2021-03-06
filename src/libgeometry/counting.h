#ifndef COUNTING_H
#define COUNTING_H

#include <string>
#include <vector>

float perim(std::vector<float>& coords);
float area(std::vector<float>& coords);
std::vector<float> sqrSum(float a, float b);
std::vector<float> QuadRoots(std::vector<float> coef);
bool cirToCir(std::vector<float> cir1, std::vector<float> cir2);
std::vector<std::vector<int>> intersects(
        std::vector<std::pair<std::string, std::vector<float>>> figlist,
        std::vector<std::vector<int>> inter);
#endif // !COUNTING_H
