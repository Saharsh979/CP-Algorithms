#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int diff = abs((int)s1.size() - (int)s2.size());
    if (diff >= 2)
    {
        cout << "FALSE" << endl;
        return 0;
    }
    int count = 0;
    map<char, int> mp1;
    map<char, int> mp2;
    for (int i = 0; i < s1.size(); i++)
    {
        mp1[s1[i]]++;
    }
    for (int i = 0; i < s2.size(); i++)
    {
        if (mp1[s2[i]])
        {
            mp1[s2[i]]--;
        }
        else
        {
            if (mp1[s1[i]])
            {
                mp1[s1[i]]--;
            }
            count++;
        }
    }
    for (auto it : mp1)
    {
        if (it.second > 0)
        {
            count++;
        }
    }
    cout << count << endl;
}