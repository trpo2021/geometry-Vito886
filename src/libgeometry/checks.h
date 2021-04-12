#ifndef CHECKS_H
#define CHECKS_H

#include <string>
#include <vector>

void error(int code, int position);
bool odz(char& item);
std::string figName(std::string& s);
std::vector<float> circleCoords(std::string& str);
std::vector<float> triangleCoords(std::string& str);
bool isTriangle(std::vector<float>& coords);

#endif // !CHECKS_H
