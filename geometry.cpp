#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
const int T = 8; // 8 ���������� � ������������

void check(string& s)
{
    string tr = "triangle(", cir = "circle(";
    for (int j = 0; j < size(s); j++) 
    {
        s[j] = tolower(s[j]); //�������� � ��������� ��������
    }
    if (s.find(tr) == 0 || s.find(cir) == 0)  // ���� ������� �����
    { 

    } 
    else 
    {
        cout << "error" << endl;
    }
}

void triangle(string& s)
{
    double mas[T]; // ������ � ����������� ������������
    int k = 0; // ������ ��� ���������� ������� � �����������
    string t = "";
    if (s.find("((") < s.find("))")) // ���� ������� ������ ������� �����
    {
        for (int i = s.find("((") + 2; i < s.find("))"); i++) // �������� ��������� ����� ������ ������ ����� "((", ������� +2
        {
            if (s[i] == 32 || s[i] == 44 || s[i] == 41) // ���� ��� ������ || ������� || ������, ������ ����� ���� ���� �����
            {
                mas[k] = stod(t);
                k++;
                if (k == T) // ���� ��� ��������� ������� �������
                {
                    // ������� ������ � ����������� � ������� �� ���������
                    for (int i = 0; i < T; i++)
                        cout << mas[i] << " ";
                    cout << endl;
                    return;
                }
            }
            if ((s[i] < 47 || s[i]>58) && (s[i] != 45 && s[i] != 46)) // ���� ��� �� �����, ����� ��� �����
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
    cout << "������� ������: " << endl;
    while (getline(cin, s)) 
    {
        if (s == "") 
        {
            break;
        }
        list.push_back(s);
    }
    check(list[0]); // ��������� ������������ ������� ������
    for (i = 0; i < list.size(); i++) 
    {
        cout << list[i] << endl;
    }
}
