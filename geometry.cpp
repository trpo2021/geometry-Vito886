#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

void check(string& s)
{
    string tr = "triangle(", cir = "circle(";
    for (int j = 0; j < size(s); j++) 
    {
        s[j] = tolower(s[j]); //приводим к строчному регистру
    }
    if (s.find(tr) == 0 || s.find(cir) == 0)  // если введено верно
    { 

    } 
    else 
    {
        cout << "error" << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    vector <string> list;
    string s;
    int i;
    cout << "¬ведите фигуры: " << endl;
    while (getline(cin, s)) 
    {
        if (s == "") 
        {
            break;
        }
        list.push_back(s);
    }
    check(list[0]); // провер€ем правильность входных данных
    for (i = 0; i < list.size(); i++) 
    {
        cout << list[i] << endl;
    }
}
