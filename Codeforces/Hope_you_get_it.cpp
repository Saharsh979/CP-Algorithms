
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int

int power(int x, unsigned int y)
{
    int p = 1000000007;
    int res = 1;
    x = x % p;

    while (y > 0)
    {
        if (y & 1)
        {
            res = (res * x) % p;
        }
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
ll productPairs(ll left, ll right, ll n)
{

    ll product = 1;
    for (int i = left; i <= right; i++)
    {
        product = (product % mod * (int)power(i, (2 * n)) % mod) % mod;
    }
    return product % mod;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll left, right;
        cin >> left >> right;
        ll initial_value = productPairs(left, right, right - left);
        ll defect = 1;
        for (ll i = left; i <= right; i++)
        {
            defect = (defect % mod * (int)power(i, 2) % mod) % mod;
        }
        ll final_answer = initial_value - defect;
        cout << final_answer << endl;
    }
    return 0;
}
