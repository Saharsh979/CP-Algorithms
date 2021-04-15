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

void generatePrintBinary(int n)
{
    queue<string> q;
    q.push("1");
    while (n--)
    {
        string s1 = q.front();
        q.pop();
        cout << s1 << "\n";
        string s2 = s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll start_interval[m];
        ll end_interval[m];
        ll d_value[m];
        ll index = 0;
        ll range = m;
        while (range--)
        {
            ll a1, a2, a3;
            cin >> a1 >> a2 >> a3;
            start_interval[index] = a1 - 1;
            end_interval[index] = a2 - 1;
            d_value[index] = a3;
            index++;
        }
        /*
        for (ll it = 0; it < n; it++)
        {
            cout << start_interval[it] << " " << end_interval[it] << " " << d_value[it] << endl
        }
        */
        vector<ll> value;
        ll flag = false;
        ll range_of_n = (1LL << n);
        for (ll i = 0; i < range_of_n; i++)
        {
            ll check_arr[n] = {0LL};

            ll sum = 0;
            for (ll j = 0; j < n; j++)
            {
                if (i & (1LL << j))
                {
                    check_arr[j] = 1LL;
                    sum += arr[j];
                }
            }
            for (ll p = 0; p < m; p++)
            {
                bool flag2 = true;
                for (ll q = start_interval[p]; q <= end_interval[p]; q++)
                {
                    if (check_arr[q] != 1)
                    {
                        flag2 = false;
                        break;
                    }
                }
                if (flag2)
                {
                    sum += d_value[p];
                }
            }
            // for (ll op = 0; op < n; op++)
            //{
            //     cout << check_arr[op] << " ";
            // }
            // cout << sum << endl;
            value.push_back(sum);
        }
        sort(all(value));
        ll size = value.size() - 1;
        ll finalindex = 0;
        while (finalindex != k)
        {
            cout << value[size] << " ";
            size--;
            finalindex++;
        }
        cout << endl;
    }
}