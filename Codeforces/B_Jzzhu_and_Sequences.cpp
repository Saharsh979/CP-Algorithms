#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int mod = 1e9 + 7;
    long long int x, y;
    cin >> x >> y;

    long long int t;
    cin >> t;

    t = t % 6;
    if (t == 0)
    {
        cout << ((x - y) + mod + mod) % mod << endl;
    }
    else if (t == 1)
    {
        cout << (x + +mod) % mod << endl;
    }
    else if (t == 2)
    {
        cout << (y + mod + mod) % mod << endl;
    }
    else if (t == 3)
    {
        cout << ((y - x) + mod + mod) % mod << endl;
    }
    else if (t == 4)
    {
        cout << (-x + mod + mod) % mod << endl;
    }
    else if (t == 5)
    {
        cout << ((-y + mod) + mod) % mod << endl;
    }
}