#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    vector <string> list;
    string s;
    int i;
    cout << "¬ведите фигуры: " << endl;
    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        list.push_back(s);
    }
    for (i = 0; i < list.size(); i++) {
        cout << list[i] << endl;
    }
}
