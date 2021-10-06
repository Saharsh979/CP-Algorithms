#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    int n = s1.length();
    bool flag = false;

    for (int i = 0; i < n; i++)
    {
        int val1 = s1[i] - '0';
        int val2 = s2[i] - '0';
        if (val1 < val2)
        {
            cout << -1 << endl;
            flag = true;
            break;
        }
        else if (val1 > val2)
        {
            cout << 1 << endl;
            flag = true;
            break;
        }
        else
        {
            continue;
        }
    }
    if (flag == false)
    {
        cout << 0 << endl;
    }
}