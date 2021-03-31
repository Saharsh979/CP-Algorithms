#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int v, c, first, second;
        cin >> v >> c >> first >> second;

        if (min(v, c) >= second && v + c >= first + second)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}