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
    long long int t;
    cin >> t;
    while (t--)
    {
        ll k, n;
        cin >> n >> k;
        string s;
        vector<pair<int, bool>> min_dist;
        cin >> s;
        ll d = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                min_dist.push_back(make_pair(i, false));
            }
        }
        ll st = min_dist[0].first;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || i == min_dist.size() - 1)
            {
                min_dist[i].second = true;
            }
            d = min_dist[i].first - st;
            if (d > k)
            {
                st = min_dist[i - 1].first;
                min_dist[i - 1].second = true;
            }
        }
        ll ans = 0;
        for (int i = 0; i < min_dist.size(); i++)
        {
            if (min_dist[i].second == true)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
}