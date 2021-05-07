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

    cout << "Input figures" << endl;

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
    vector<vector<int>> inter;
    inter.resize(figlist.size());
    int t1 = figlist.size();
    inter = intersects(figlist, inter);
    for (int i = 0; i < t1; i++) {
        cout << i + 1 << ". " << figlist[i].first << ": ";
        int t2 = figlist[i].second.size();
        for (int j = 0; j < t2; j++) {
            cout << figlist[i].second[j] << " ";
        }
        cout << endl << "   perimeter = " << perim(figlist[i].second) << endl;
        cout << "   area = " << area(figlist[i].second) << endl;
        cout << "    intersects:" << endl;
        int m = inter[i].size();
        if (m > 0) {
            for (int j = 0; j < m; j++) {
                cout << "      " << inter[i][j] + 1 << ". "
                     << figlist[inter[i][j]].first << endl;
            }
            cout << endl;
        } else
            cout << "       none" << endl << endl;
        cout << endl;
    }
    system("pause");
}
