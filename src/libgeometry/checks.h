#ifndef CHECKS_H
#define CHECKS_H

#include <string>
#include <vector>

using namespace std;

void error(int code, int position);
bool odz(char& item);
string figName(string& s);
vector<float> circleCoords(string& str);
vector<float> triangleCoords(string& str);
bool isTriangle(vector<float>& coords);

#endif // !CHECKS_H
