#include <iostream>
#include <map>
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


int main()
{
    setlocale(LC_CTYPE, "Russian");
 
    cout << "Задайте фигуры" << endl;
}