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

#include <bits/stdc++.h>
#define ll long long int
ll mod = (int)1e9 + 7;
#define mod2 998244353
#define pb push_back
#define run(x, v) for (auto x : v)
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repb(i, a, b) for (int i = a; i >= b; i--)

#define mp make_pair
#define pb push_back
#define inp(a, n) \
    ru(i, n) { cin >> a[i]; }
#define sv(v) sort(v.begin(), v.end())
#define sa(a) sort(a, a + size(a) / size(a[0]))
using namespace std;
#define m1 -1e16
#define m2 1e16
#define ff first
#define ss second

void solve(int t)
{
    ll n, m;
    cin >> n >> m;
    vector < vector<int> a(n, vector<int>(m));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector < vector<int> b(n, vector<int>(m));
    int k = 0;
    vector<int> mx(m);
    sort(a[0].begin(), a[0].end());
    for (int i = 0; i < m; i++)
    {
        mx[i] = a[0][i];
    }
    for (i = 0; i < n; i++)
    {
        sort(a[i].begin(), a[i].end());
        k = 0;
        if (i != 0)
        {
            for (j = 0; j < m; j++)
            {
                if (mx[j] > a[i][j])
                    break;
                k++;
            }
        }
        for (j = 0; j < m; j++)
        {
            b[i][(j + k) % m] = a[i][j];
            mx[j] = min(mx[j], a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
    //cout<<ans<<"\n";
}
signed main()
{
    int t = 1;
    cin >> t;
    rep(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}

sanjeev1110 @gmail.com
