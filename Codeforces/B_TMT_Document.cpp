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
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        ll sumt = 0;
        ll summ = 0;
        cin >> n;
        string s;
        cin >> s;
        for (auto x : s)
        {
            if (x == 'T')
            {
                sumt++;
            }
            else
            {
                summ++;
            }
        }
        ll val = n / 3;
        if (sumt == 2 * summ)
        {
            bool flag = true;
            ll tt = 0;
            ll mm = 0;
            for (auto x : s)
            {
                if (x == 'T')
                {
                    tt++;
                    if (tt - mm > val)
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    mm++;
                    if (mm > tt)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}