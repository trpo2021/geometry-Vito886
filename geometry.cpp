#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

const float pi = 3.1415;

void error(int code, int position)
{
    for (int i = 0; i < position; i++) 
    {
        cout << " ";
    }
    cout << "^" << endl;

    switch (code) 
    {
    case 1:
        cout << "Error at column " << position
             << "expected 'circle' or 'triangle'; code = " << code << endl;
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
    }
}

bool odz(string& item)
{
    if (((item < 48) || (item > 57)) && (item != 32) && (item != 44)
        && (item != 45) && (item != 46)) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

string figName(string& s)
{
    string name = "";
    int stringSize = s.length();
    for (int i = 0; i < stringSize; i++)
    {
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

    if (end == -1) 
    {
        error(3, s.length() - 1);
        ccoords.clear();
        return ccoords;
    }

    string tempMas = "";
    tempMas = s.substr(start);

    if (tempMas[0] == '(') 
    {
        tempMas.erase(0, 1);
    } 
    else
    {
        error(5, 8);
        ccoords.clear();
        return ccoords;
    }
    int length = tempMas.length();
    for (int i = 0; i < length; i++) 
    {
        elem = "";
        if (count < 2) 
        {
            if (odz(tempMas[i]) == 1) 
            {
                error(2, pos);
                ccoords.clear();
                return ccoords;
            }
            if (tempMas[i] == ' ') 
            {
                if (tempMas[i + 1] == ' ') 
                {
                    pos++;
                } 
                else
                {
                    elem += tempMas.substr(0, i);
                    ccoords.push_back(stof(elem));
                    tempMas.erase(0, i + 1);
                    length = tempMas.length();
                    i = 0;
                    count++;
                    pos++;
                }
            }
            if (tempMas[i] == ',') 
            {
                elem += tempMas.substr(0, i);
                ccoords.push_back(stof(elem));
                tempMas.erase(0, i + 2);
                length = tempMas.length();
                i = 0;
                count++;
                pos += 2;
            }
        } 
        else if (count == 2) 
        {
            if (end != -1) 
            {
                elem += tempMas.substr(0, end);
                ccoords.push_back(stof(elem));
                tempMas.erase(0, end + 1);
                length = tempMas.length();
                i = 0;
                count++;
            } 
            else 
            {
                error(3, pos);
                ccoords.clear();
                return ccoords;
            }
        } 
        else 
        {
            error(4, str.find(")") + 1);
            ccoords.clear();
            return ccoords;
        }
        pos++;
    }
    return ccoords;
}

vector<float> triangleCoords(string& str)
{
    string s = str, elem;
    vector<float> tcoords;
    int start = s.find("(("), end = s.find("))"), count = 0, pos = 10;
    if (end == -1) 
    {
        error(3, s.length() - 1);
        tcoords.clear();
        return tcoords;
    }

    string tempMas = "";
    tempMas = s.substr(start);

    if ((tempMas[0] == '(') && (tempMas[1] == '(')) 
    {
        tempMas.erase(0, 2);
    } 
    else 
    {
        error(5, 8);
        tcoords.clear();
        return tcoords;
    }
    int length = tempMas.length();
    for (int i = 0; i < length; i++) 
    {
        elem = "";
        if (count < 7) 
        {
            if (odz(tempMas[i]) == 1) 
            {
                error(2, pos);
                tcoords.clear();
                return tcoords;
            }
            if (tempMas[i] == ' ') 
            {
                if (tempMas[i + 1] == ' ')
                {
                    pos++;
                } 
                else
                {
                    elem += tempMas.substr(0, i);
                    tcoords.push_back(stof(elem));
                    tempMas.erase(0, i + 1);
                    length = tempMas.length();
                    i = 0;
                    count++;
                    pos++;
                } 
            }
            if (tempMas[i] == ',') 
            {
                elem += tempMas.substr(0, i);
                tcoords.push_back(stof(elem));
                tempMas.erase(0, i + 2);
                length = tempMas.length();
                i = 0;
                count++;
                pos += 2;
            }
        } 
        else if (count == 7) 
        {
            int end = tempMas.find("))");
            if (end != -1) 
            {
                elem += tempMas.substr(0, end);
                tcoords.push_back(stof(elem));
                tempMas.erase(0, end + 2);
                length = tempMas.length();
                i = 0;
                count += 2;
            } 
            else 
            {
                error(3, pos);
                tcoords.clear();
                return tcoords;
            }
        } 
        else 
        {
            error(4, str.find("))") + 2);
            tcoords.clear();
            return tcoords;
        }
        pos++;
    }
    return tcoords;
}

float side1(vector<float>& coords)
{
    vector<float> c = coords;
    float line = sqrt(pow(c[3] - c[1], 2) + pow(c[4] - c[2], 2));
    return line;
}

float side2(vector<float>& coords)
{
    vector<float> c = coords;
    float line = sqrt(pow(c[5] - c[3], 2) + pow(c[6] - c[4], 2));
    return line;
}

float side3(vector<float>& coords)
{
    vector<float> c = coords;
    float line = sqrt(pow(c[5] - c[1], 2) + pow(c[6] - c[2], 2));
    return line;
}

float perim(vector<float>& coords) 
{
    vector<float> c = coords;

    if (c.size() > 3)
    {
        float line1 = side1(c);
        float line2 = side2(c);
        float line3 = side3(c);  
        if ((line1 + line2 > line3) && (line2 + line3 > line1) && (line1 + line3 > line2)) 
        { 
            return line1 + line2 + line3; 
        } 
        else
        {
            return 1; // выход с ошибкой
        }
    } 
    else 
    { 
        return 2 * pi * c[2]; 
    }
}

int main()
{
    setlocale(LC_CTYPE, "Russian");

    vector<pair<string, vector<float>>> figlist;
    string s;

    cout << "Задайте фигуры" << endl;

    while (getline(cin, s)) 
    {
        if (s == "") 
        {
            break;
        }

        vector<float> figureCoords;
        string figureName = figName(s);
        pair<string, vector<float>> figure;

        if (figureName == "triangle") 
        {
            figureCoords = triangleCoords(s);
        } 
        else if (figureName == "circle") 
        {
            figureCoords = circleCoords(s);
        } 
        else 
        {
            error(1, 0);
        }
        if (figureCoords.size() > 0) 
        {
            figure.first = figureName;
            figure.second = figureCoords;
            figlist.push_back(figure);
        }
    }
    int t1 = figlist.size();
    for (int i = 0; i < t1; i++) 
    {
        cout << i + 1 << ". " << figlist[i].first << ": ";
        int t2 = figlist[i].second.size();
        for (int j = 0; j < t2; j++) 
        {
            cout << figlist[i].second[j] << " ";
        }
        cout << endl;
    }
}
