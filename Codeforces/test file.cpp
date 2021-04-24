#include <bits/stdc++.h>
using namespace std;

void recurse(string s, string curr, int pos, int n)
{
    if (pos == n)
    {
        cout << curr << endl;
    }
    else if (s[pos] == '1' || s[pos] == '0')
    {
        curr.push_back(s[pos]);
        pos = pos + 1;
    }
    else
    {
        pos = pos + 1;
        string curr1 = curr;
        curr1.push_back('1');
        string curr2 = "";
        curr2.push_back('0');
        recurse(s, curr1, pos, n);
        recurse(s, curr2, pos, n);
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string curr = "";
        recurse(s, curr, 0, s.length());
    }
}