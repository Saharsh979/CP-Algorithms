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
    ll arr[n];
    ll count_even = 0;
    ll count_odd = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2)
        {
            count_odd++;
        }
        else
        {
            count_even++;
        }
    }
    if (abs(count_even - count_odd) >= 2)
    {
        vector<ll> even;
        vector<ll> odd;
        for (ll i = 0; i < n; i++)
        {
            if (arr[i] % 2)
            {
                odd.push_back(arr[i]);
            }
            else
            {
                even.push_back(arr[i]);
            }
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        ll val = min(odd.size(), even.size());
        ll limit_even = even.size() - val;
        ll limit_odd = odd.size() - val;
        if (limit_even != 0)
        {
            limit_even--;
        }
        else
        {
            limit_odd--;
        }
        ll answer = 0;
        if (limit_odd == 0)
        {
            for (ll i = 0; i < limit_even; i++)
            {
                answer += even[i];
            }
        }
        else
        {
            for (ll i = 0; i < limit_odd; i++)
            {
                answer += odd[i];
            }
        }
        cout << answer << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}
