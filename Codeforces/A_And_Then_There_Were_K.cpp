#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll highest(ll n)
{
    ll p = (ll)log2(n);
    return (ll)pow(2, p);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        if (n == 1)
        {
            cout << 0 << endl;
        }
        else
        {
            ll val = highest(n);
            cout << val - 1 << endl;
        }
    }
}