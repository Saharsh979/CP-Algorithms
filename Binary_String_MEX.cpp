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

bool solve(string t, string s)
{
    if (s == t)
    {
        return true;
    }
    ll n = s.size();
    ll m = t.size();
    ll j = 0;
    for (ll i = 0; i < n; i++)
    {
        if (t[j] == s[i])
        {
            j++;
        }
        if (j == t.size())
        {
            return true;
        }
    }
    return false;
}
string decimalToBinary(ll n)
{
    string s = bitset<64>(n).to_string();
    const auto loc1 = s.find('1');
    if (loc1 != string::npos)
    {
        return s.substr(loc1);
    }
    return "0";
}

ll dp_1[1000006];
ll dp_2[1000006];
ll next_zero[1000000];
ll next_one[1000000];

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        bool flag1 = false;
        bool flag2 = false;

        ll n = s.length();
        ll last_pos = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                for (ll j = last_pos + 1; j <= i; j++)
                {
                    next_zero[j] = i;
                }
                last_pos = i;
            }
        }
        for (ll i = last_pos + 1; i < n; i++)
        {
            next_zero[i] = n;
        }
        if (next_zero[0] == n)
        {
            cout << "0" << '\n';
            flag1 = true;
            continue;
        }
        last_pos = -1;
        for (ll i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                for (ll j = last_pos + 1; j <= i; j++)
                {
                    next_one[j] = i;
                }
                last_pos = i;
            }
        }
        for (ll i = last_pos + 1; i < n; i++)
        {
            next_one[i] = n;
        }

        dp_1[n] = 0;
        dp_1[n + 1] = 0;
        dp_2[n] = 0;
        dp_2[n + 1] = 0;

        for (ll i = n - 1; i >= 0; --i)
        {
            dp_1[i] = dp_1[i + 1];
            if (s[i] == '0' && next_one[i] < n)
            {
                dp_1[i] = max(dp_1[i], dp_1[next_one[i] + 1] + 1);
            }
            if (s[i] == '1' && next_zero[i] < n)
            {
                dp_1[i] = max(dp_1[i], dp_1[next_zero[i] + 1] + 1);
            }
            dp_2[i] = dp_2[i + 1];
            if (next_one[i] < n)
            {
                dp_2[i] = max(dp_2[i], dp_1[next_one[i] + 1] + 1);
            }
        }

        ll length = dp_2[0] + 1;
        ll current_index = next_one[0] + 1;

        string ans = "1";
        for (ll i = 1; i < length; ++i)
        {
            if (current_index >= n)
            {
                ans.push_back('0');
                continue;
            }
            if (next_zero[current_index] >= n)
            {
                ans.push_back('0');
                current_index = next_zero[current_index] + 1;
                continue;
            }
            if (dp_1[next_zero[current_index] + 1] < length - i - 1)
            {
                ans.push_back('0');
                current_index = next_zero[current_index] + 1;
            }
            else
            {
                ans.push_back('1');
                current_index = next_one[current_index] + 1;
            }
        }
        if (flag1 == false)
        {
            cout << ans << "\n";
        }
    }
}