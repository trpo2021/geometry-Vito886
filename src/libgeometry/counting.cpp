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

vector<float> QuadRoots(vector<float> coef) 
{
    vector<float> roots(0);
    struct abc {
        float a;
        float b;
        float c;
    };
    abc arg = {coef[0], coef[1], coef[2]};
    float d = arg.b * arg.b - 4 * arg.a * arg.c;
    if (d < 0)
        return roots;
    else if (d > 0) {
        roots.push_back((-arg.b + sqrt(d)) / (2 * arg.a));
        roots.push_back((-arg.b - sqrt(d)) / (2 * arg.a));
        return roots;
    } else if (d == 0) {
        roots.push_back(-arg.b / (2 * arg.a));
        return roots;
    } else
        return roots;
}

bool cirToCir(vector<float> cir1, vector<float> cir2)
{
    bool root = 0;
    int i;
    cir1[2] *= cir1[2];
    cir2[2] *= cir2[2];
    vector<float> xfirst = sqrSum(1, cir1[0]);
    vector<float> yfirst = sqrSum(1, cir1[1]);
    vector<float> xsec = sqrSum(1, cir2[0]);
    vector<float> ysec = sqrSum(1, cir2[1]);
    vector<float> tempx = xfirst;
    tempx[2] += yfirst[2] - cir1[2];
    for (i = 0; i < 3; i++) {
        xfirst[i] -= xsec[i];
        yfirst[i] -= ysec[i];
    }
    yfirst[2] += xfirst[2] - (cir1[2] - cir2[2]);
    xfirst[2] = 0;
    yfirst[2] = -yfirst[2];
    vector<float> afterminus;
    afterminus.push_back(xfirst[1]);
    for (i = 1; i < 3; i++)
        afterminus.push_back(yfirst[i]); 
    vector<float> sqy = sqrSum(
            -afterminus[0] / afterminus[1], afterminus[2] / afterminus[1]);
    for (i = 0; i < 3; i++)
        tempx[i] += sqy[i];
    tempx[1] += -afterminus[0] / afterminus[1];
    tempx[2] += afterminus[2] / afterminus[1];
    tempx = QuadRoots(tempx);
    if (tempx.size() > 0)
        return root = 1;
    else
        return root; 
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
