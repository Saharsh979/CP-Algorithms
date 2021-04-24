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

int main()
{
    ll n;
    cin >> n;
    ll type1[n + 1];
    ll type2[n + 1];
    memset(type1, 0, sizeof(type1));
    memset(type2, 0, sizeof(type2));
    for (ll i = 1; i <= n; i++)
    {
        ll type, val;
        cin >> type >> val;
        if (type == 1)
        {
            if (i > 0)
            {
                type1[i] = val + type1[i - 1];
                type2[i] = type2[i - 1];
            }
            else
            {
                type1[i] = val;
                type2[i] = 0;
            }
        }
        else
        {
            if (i == 0)
            {
                type2[i] = val;
                type1[i] = 0;
            }
            else
            {
                type2[i] = val + type2[i - 1];
                type1[i] = type1[i - 1];
            }
        }
    }
    ll q;
    cin >> q;
    while (q--)
    {

        ll left, right;
        cin >> left >> right;
        ll first = type1[right] - type1[left - 1];
        ll second = type2[right] - type2[left - 1];
        cout << first << " " << second << endl;
    }
}