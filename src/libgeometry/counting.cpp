#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const float pi = 3.1415;

float perim(vector<float>& coords)
{
    return 2 * pi * coords[2];
}

float area(vector<float>& coords)
{
    return pi * pow(coords[2], 2);
}
