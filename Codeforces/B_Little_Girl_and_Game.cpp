#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int count = 0;
    int ones = 0;
    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    int odd = 0;
    int even = 0;

    for (auto it : mp)
    {
        if (it.second % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (odd % 2 == 1 || odd == 0)
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
}