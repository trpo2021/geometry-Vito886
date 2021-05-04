#include "counting.h"
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void error(int code, int position)
{
    for (int i = 0; i < position; i++) {
        cout << " ";
    }
    cout << "^" << endl;

    switch (code) {
    case 1:
        cout << "Error at column " << position
             << "expected 'circle'; code = " << code << endl;
        break;
    case 2:
        cout << "Error at column " << position
             << ": expected '<double>'; code = " << code << endl;
        break;
    case 3:
        cout << "Error at column " << position
             << ": expected ')'; code = " << code << endl;
        break;
    case 4:
        cout << "Error at column " << position
             << ": unexpected token; code = " << code << endl;
        break;
    case 5:
        cout << "Error at column " << position
             << ": expected '('; code = " << code << endl;
        break;
    case 6:
        cout << "Error at column " << position
             << ": minus in radius; code = " << code << endl;
        break;
    }
}

bool odz(char& item)
{
    if (((item < '0') || (item > '9')) && (item != ' ') && (item != ',')
        && (item != '-') && (item != '.')) {
        return 1;
    } else {
        return 0;
    }
}

string figName(string& s)
{
    string name = "";
    int stringSize = s.length();
    for (int i = 0; i < stringSize; i++) {
        s[i] = tolower(s[i]); // приводим к строчному регистру
    }

    int end = s.find("(");
    name = s.substr(0, end);
    return name;
}

vector<float> circleCoords(string& str)
{
    string s = str, elem;

    vector<float> ccoords;
    int start = s.find("("), end = s.find(")"), count = 0, pos = 8;

    if (end == -1) {
        error(3, s.length() - 1);
        ccoords.clear();
        return ccoords;
    }

    string tempMas = "";
    tempMas = s.substr(start);

    if (tempMas[0] == '(') {
        tempMas.erase(0, 1);
    } else {
        error(5, 8);
        ccoords.clear();
        return ccoords;
    }
    int length = tempMas.length();
    for (int i = 0; i < length; i++) {
        elem = "";
        if (count < 2) {
            if (odz(tempMas[i]) == 1) {
                error(2, pos);
                ccoords.clear();
                return ccoords;
            }
            if (tempMas[i] == ' ') {
                if (tempMas[i + 1] == ' ') {
                    pos++;
                } else {
                    elem += tempMas.substr(0, i);
                    ccoords.push_back(stof(elem));
                    tempMas.erase(0, i + 1);
                    length = tempMas.length();
                    i = 0;
                    count++;
                    pos++;
                }
            }
            if (tempMas[i] == ',') {
                elem += tempMas.substr(0, i);
                ccoords.push_back(stof(elem));
                tempMas.erase(0, i + 2);
                length = tempMas.length();
                i = 0;
                count++;
                pos += 2;
            }
        } else if (count == 2) {
            if (end != -1) {
                elem += tempMas.substr(0, end);
                if (stof(elem) < 0) {
                    error(6, pos);
                    ccoords.clear();
                    return ccoords;
                } else {
                    ccoords.push_back(stof(elem));
                    tempMas.erase(0, end + 1);
                    length = tempMas.length();
                    i = 0;
                    count++;
                }
            } else {
                error(3, pos);
                ccoords.clear();
                return ccoords;
            }
        } else {
            error(4, str.find(")") + 1);
            ccoords.clear();
            return ccoords;
        }
        pos++;
    }
    return ccoords;
}
