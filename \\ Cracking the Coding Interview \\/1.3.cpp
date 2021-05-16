#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!isspace(s[i]))
        {
            res.push_back(s[i]);
        }
        else
        {
            res = res + "%20";
        }
    }
    cout << res << endl;
}
