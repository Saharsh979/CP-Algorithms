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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll arr[n][m];
        ll count = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {

                cin >> arr[i][j];
                if (arr[i][j] >= k)
                {
                    //count++;
                }
            }
        }
        ll initial[n][m];
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                initial[i][j] = arr[i][j];
            }
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 1; j < m; j++)
            {
                initial[i][j] += initial[i][j - 1];
            }
        }
        for (ll j = 0; j < m; j++)
        {
            for (ll i = 1; i < n; i++)
            {
                initial[i][j] += initial[i - 1][j];
            }
        }
        ll prefix[n + 1][m + 1];

        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                if (i == 0 || j == 0)
                {
                    prefix[i][j] = 0;
                }
                else
                {
                    prefix[i][j] = initial[i - 1][j - 1];
                }
            }
        }
        /*
        for (ll i = 0; i <= n; i++)
        {
            for (ll j = 0; j <= m; j++)
            {
                cout << prefix[i][j] << " ";
            }
            cout << endl;
        }
        */
        ll max_dim = min(n, m);
        ll size = 1;
        while (size <= max_dim)
        {
            ll i = size;
            ll j = m;
            while (i <= n)
            {
                ll x = i - size + 1;
                ll y = j - size + 1;

                ll z = prefix[i][j] - prefix[x - 1][j] - prefix[i][y - 1] + prefix[x - 1][y - 1];
                ll value = (z / (size * size));
                if (value < k)
                {
                    i++;
                }
                else
                {
                    ll temp_ans = -1;
                    ll start_index = size;
                    ll end_index = m;
                    while (start_index <= end_index)
                    {
                        ll mid = ((start_index + end_index) / 2);
                        x = i - size + 1;
                        y = mid - size + 1;
                        z = prefix[i][mid] - prefix[x - 1][mid] - prefix[i][y - 1] + prefix[x - 1][y - 1];
                        ll new_value = (z / (size * size));
                        if (new_value < k)
                        {
                            start_index = mid + 1;
                        }
                        else
                        {
                            temp_ans = mid;
                            end_index = mid - 1;
                        }
                    }
                    //cout << temp_ans << endl;
                    count += m - temp_ans + 1;
                    i++;
                }
            }
            size++;
        }
        cout << count << endl;
    }
}
