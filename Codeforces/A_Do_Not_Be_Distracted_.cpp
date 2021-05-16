#include <bits/stdc++.h>
using namespace std;

bool solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> seen;
    for (int i = 0; i < n; i++)
    {
        if (seen[s[i]] && s[i] != s[i - 1])
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {
            seen[s[i]] = 1;
        }
    }
    cout << "YES" << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}