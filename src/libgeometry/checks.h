#ifndef CHECKS_H
#define CHECKS_H

#include <string>
#include <vector>

void error(int code, int position);
bool odz(char& item);
std::string figName(std::string& s);
std::vector<float> circleCoords(std::string& str);

#endif // !CHECKS_H
