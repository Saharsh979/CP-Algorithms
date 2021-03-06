#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#define sz(a) (int)a.size()
#define pb push_back
#define vmin *min_element
#define vmax *max_element
#define max_pq priority_queue<ll, vector<ll>>
#define min_pq priority_queue<ll, vector<ll>, greater<ll>>
#define all(x) x.begin(), x.end()
#define ub upper_bound
#define lb lower_bound
#define bin binary_search
#define revsort(v) sort(all(v), greater<int>())
#define min(a, b) min((int)a, (int)b)
#define max(a, b) max((int)a, (int)b)
#define min3(a, b, c) min(min(a, b), c)
#define max3(a, b, c) max(max(a, b), c)
#define ll long long int //int64_t
#define endl '\n'
#define uint unsigned long long int // uint64_t
#define ld long double
#define setbits(x) __builtin_popcountll(x)
#define zrobits(x) __builtin_ctzll(x)
#define preci(x, y) fixed << setprecision(y) << x

bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
ll factorial(ll n) { return (n == 1 || n == 0) ? 1 : n * factorial(n - 1); }
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
ll lcm(ll a, ll b) { return (a / gcd(a, b) * b); }
ll max(ll a, ll b)
{
    ll sol = a > b ? a : b;
    return sol;
}
ll min(ll a, ll b)
{
    ll sol = a < b ? a : b;
    return sol;
}

ll fnd(ll n)
{
    if (n < 2050 || n % 2050)
        return -1;
    n /= 2050;
    ll c = 0;
    while (n)
    {
        c += n % 10;
        n /= 10;
    }
    return c;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << fnd(n) << endl;
    }
    return 0;
}