#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << " " << 0 << endl;
        }
        else if (abs(a - b) == 1)
        {
            cout << 1 << " " << 0 << endl;
        }
        else if (a == 0 || b == 0)
        {
            cout << abs(a - b) << " " << 0 << endl;
        }
        else
        {
            if (a > b)
            {
                swap(a, b);
            }
            if (b % (b - a) == 0)
            {
                cout << b - a << " " << 0 << endl;
            }
            else
            {
                ll x = b / (b - a);
                ll y = x + 1;
                ll smaller = x * (b - a);
                ll bigger = y * (b - a);

                ll val1 = b - smaller;
                ll val2 = bigger - b;
                cout << b - a << " " << min(val1, val2) << endl;
            }
        }
    }
}