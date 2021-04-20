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

vector<float> sqrSum(float a, float b)
{
    vector<float> resSqr;
    resSqr.push_back(a * a);
    resSqr.push_back(2 * a * b);
    resSqr.push_back(b * b);
    return resSqr;
}

vector<float> sqrEq(vector<float> coef)
{
    vector<float> radical(0);
    struct abc {
        float a;
        float b;
        float c;
    };
    abc arg = {coef[0], coef[1], coef[2]};
    float d = arg.b * arg.b - 4 * arg.a * arg.c;
    if (d < 0)
        return radical;
    else if (d > 0) {
        radical.push_back((-arg.b + sqrt(d)) / (2 * arg.a));
        radical.push_back((-arg.b - sqrt(d)) / (2 * arg.a));
        return radical;
    } else if (d == 0) {
        radical.push_back(-arg.b / (2 * arg.a));
        return radical;
    } else
        return radical;
}

bool cirToCir(vector<float> cir1, vector<float> cir2)
{
    bool cross = 0;
    int i;
    cir1[2] *= cir1[2];
    cir2[2] *= cir2[2];
    vector<float> xone = sqrSum(1, cir1[0]);
    vector<float> yone = sqrSum(1, cir1[1]);
    vector<float> xsec = sqrSum(1, cir2[0]);
    vector<float> ysec = sqrSum(1, cir2[1]);
    vector<float> tx = xone;
    tx[2] += yone[2] - cir1[2];
    for (i = 0; i < 3; i++) {
        xone[i] -= xsec[i];
        yone[i] -= ysec[i];
    }
    yone[2] += xone[2] - (cir1[2] - cir2[2]);
    xone[2] = 0;
    yone[2] = -yone[2];
    vector<float> afterminus;
    afterminus.push_back(xone[1]);
    for (i = 1; i < 3; i++)
        afterminus.push_back(yone[i]);
    vector<float> sqy = sqrSum(
            -afterminus[0] / afterminus[1], afterminus[2] / afterminus[1]);
    for (i = 0; i < 3; i++)
        tx[i] += sqy[i];
    tx[1] += -afterminus[0] / afterminus[1];
    tx[2] += afterminus[2] / afterminus[1];
    tx = sqrEq(tx);
    if (tx.size() > 0)
        return cross = 1;
    else
        return cross;
}

vector<vector<int>> intersects(
        vector<pair<string, vector<float>>> figlist, vector<vector<int>> inter)
{
    int i, j, z = figlist.size();
    vector<int> repeat;
    for (i = 0; i < z; i++) {
        for (j = i + 1; j < z; j++) {
            if (cirToCir(figlist[i].second, figlist[j].second)) {
                inter[i].push_back(j);
                inter[j].push_back(i);
            }
        }
    }
    return inter;
}
