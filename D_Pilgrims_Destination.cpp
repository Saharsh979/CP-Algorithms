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

ll dis[100001];
vector<ll> adjacency_list[100001];
void journey(ll v, ll p, ll l, map<pair<ll, ll>, ll> mp)
{
    if (p != -1)
    {
        dis[v] = l * mp[make_pair(min(v, p), max(v, p))] + dis[p];
    }
    for (ll i = 0; i < adjacency_list[v].size(); i++)
    {
        if (adjacency_list[v][i] != p)
        {
            journey(adjacency_list[v][i], v, l + 1, mp);
        }
    }
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        ll a[m];
        for (ll i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        for (ll i = 0; i < n; i++)
        {
            adjacency_list[i].clear();
            dis[i] = 0;
        }
        map<pair<ll, ll>, ll> mp;
        for (ll i = 0; i < n - 1; i++)
        {
            ll x, y;
            ll k;
            cin >> x >> y >> k;
            x--;
            y--;
            adjacency_list[x].push_back(y);
            adjacency_list[y].push_back(x);
            mp[make_pair(min(x, y), max(x, y))] = k;
        }
        journey(0, -1, 0, mp);
        vector<ll> pilgrims;
        for (ll i = 0; i < n; i++)
        {
            if (i != 0 && adjacency_list[i].size() == 1)
            {
                pilgrims.push_back(dis[i]);
            }
        }
        sort(pilgrims.begin(), pilgrims.end());
        sort(a, a + n);

        ll x = -1;
        ll yy = 0;
        ll j = 0;

        for (ll i = 0; i < pilgrims.size(); i++)
        {
            while (j < m && a[j] < pilgrims[i])
            {
                j++;

                if (j < m)
                {
                    j++;
                }
                if (j == m)
                {
                    x = i;
                    yy = 1;
                    break;
                }
            }
        }
        if (yy == 0)
        {
            cout << pilgrims.size() << endl;
        }
        else
        {
            cout << x << endl;
        }
    }
    return 0;
}