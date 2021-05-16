#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 1;
    string res = "";
    res.push_back(s[0]);
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] != s[i - 1])
        {
            char num = '0' + count;
            res.push_back(num);
            res.push_back(s[i]);
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if (res.size() < s.size())
    {
        cout << res << endl;
    }
    else
    {
        cout << s << endl;
    }
}