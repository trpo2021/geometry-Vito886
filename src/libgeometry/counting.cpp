#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

float side1(vector<float>& coords)
{
    return sqrt(pow(coords[2] - coords[0], 2) + pow(coords[3] - coords[1], 2));
}

float side2(vector<float>& coords)
{
    return sqrt(pow(coords[4] - coords[2], 2) + pow(coords[5] - coords[3], 2));
}

float side3(vector<float>& coords)
{
    return sqrt(pow(coords[6] - coords[4], 2) + pow(coords[7] - coords[5], 2));
}

float perim(vector<float>& coords)
{
    if (coords.size() > 3) 
    {
        return side1(coords) + side2(coords) + side3(coords);
    } 
    else 
    {
        return 2 * pi * coords[2];
    }
}

float area(vector<float>& coords)
{
    if (coords.size() > 3) 
    {
        float poluper = perim(coords) / 2;
        float square = sqrt(poluper * (poluper - side1(coords)) * (poluper - side2(coords)) * (poluper - side3(coords)));
        return square;
    } 
    else 
    {
        return pi * pow(coords[2], 2);
    }
}