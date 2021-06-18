#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (char x = 'a'; x <= 'z'; x++)
    {
        cout << "Count of" << x << " "
             << "is"
             << " " << mp[x] << endl;
    }
}