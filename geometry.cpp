#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
const int T = 8; // 8 параметров у треугольника

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

void triangle(string& s)
{
    double mas[T]; // массив с параметрами треугольника
    int k = 0; // индекс для заполнения массива с параметрами
    string t = "";
    if (s.find("((") < s.find("))")) // если порядок скобок соблюдён верно
    {
        for (int i = s.find("((") + 2; i < s.find("))"); i++) // начинаем считывать после первый символ после "((", поэтому +2
        {
            if (s[i] == 32 || s[i] == 44 || s[i] == 41) // если это пробел || запятая || скобка, значит перед этим было число
            {
                mas[k] = stod(t);
                k++;
                if (k == T) // если это последний элемент массива
                {
                    // выводим массив с параметрами и выходим из процедуры
                    for (int i = 0; i < T; i++)
                        cout << mas[i] << " ";
                    cout << endl;
                    return;
                }
            }
            if ((s[i] < 47 || s[i]>58) && (s[i] != 45 && s[i] != 46)) // если это не цифра, минус или точка
            {
                cout << "error" << endl;
                return;
            }
            t += s[i];
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "RUSSIAN");
    vector <string> list;
    string s;
    int i;
    cout << "Введите фигуры: " << endl;
    while (getline(cin, s)) 
    {
        if (s == "") 
        {
            break;
        }
        list.push_back(s);
    }
    check(list[0]); // проверяем правильность входных данных
    for (i = 0; i < list.size(); i++) 
    {
        cout << list[i] << endl;
    }
}
