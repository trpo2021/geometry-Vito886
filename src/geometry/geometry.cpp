#include <cmath>
#include <iostream>
#include <libgeometry/checks.h>
#include <libgeometry/counting.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_CTYPE, "Russian");

    vector<pair<string, vector<float>>> figlist;
    string s;

    cout << "Задайте фигуры" << endl;

    while (getline(cin, s)) {
        if (s == "") {
            break;
        }

        vector<float> figureCoords;
        string figureName = figName(s);
        pair<string, vector<float>> figure;

        if (figureName == "circle") {
            figureCoords = circleCoords(s);
        } else {
            error(1, 0);
        }
        if (figureCoords.size() > 0) {
            figure.first = figureName;
            figure.second = figureCoords;
            figlist.push_back(figure);
        }
    }
    int t1 = figlist.size();
    for (int i = 0; i < t1; i++) {
        cout << i + 1 << ". " << figlist[i].first << ": ";
        int t2 = figlist[i].second.size();
        for (int j = 0; j < t2; j++) {
            cout << figlist[i].second[j] << " ";
        }
        cout << endl << "   perimeter = " << perim(figlist[i].second) << endl;
        cout << "   area = " << area(figlist[i].second) << endl;

        cout << endl;
    }
    system("pause");
}
