#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;
    map<char, int> mp;
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    if (mp.size() != s.size())
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }
}

// What if you cant use an additional data structure;
//Sort the string
//check if(s[i]==s[i+1]) return true else false;