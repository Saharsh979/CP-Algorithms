#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    int even = 0;
    int odd = 0;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second % 2)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    if (odd == 1 || odd == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}