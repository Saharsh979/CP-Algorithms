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
    for (int case_no = 1; case_no <= t; case_no++)
    {
        cout << "Case #" << case_no << ": ";
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        int ans = 0;
        char smaller = ((x < y) ? 'C' : 'J');
        bool flag = false;
        int i = 0;
        while (i < s.length())
        {
            if (s[i] == 'C' || s[i] == 'J')
            {
                i++;
                continue;
            }
            else
            {
                if (i == 0)
                {
                    if (s[i + 1] != '?')
                    {
                        s[i] = s[i + 1];
                        i++;
                    }
                    else
                    {
                        int idx = i + 1;
                        while (s[idx] == '?')
                        {
                            idx++;
                        }
                        if (idx == s.length())
                        {
                            cout << 0 << "\n";
                            flag = true;
                            i++;
                            break;
                        }
                        else
                        {
                            for (int x = i; x < idx; x++)
                            {
                                s[x] = s[idx];
                            }
                            i = idx + 1;
                        }
                    }
                }
                else if (i == s.length() - 1)
                {
                    s[i] = s[i - 1];
                    i++;
                }
                else if (s[i - 1] == 'C' && s[i + 1] == 'C')
                {
                    s[i] = 'C';
                    i++;
                }
                else if (s[i - 1] == 'J' && s[i + 1] == 'J')
                {
                    s[i] = 'J';
                    i++;
                }
                else if (s[i - 1] == 'C' && s[i + 1] == 'J')
                {
                    s[i] = smaller;
                    i++;
                }
                else if (s[i - 1] == 'J' && s[i + 1] == 'C')
                {
                    s[i] = smaller;
                    i++;
                }
                else if (s[i - 1] == 'C' && s[i + 1] == '?')
                {
                    s[i] = s[i - 1];
                    i++;
                }
                else if (s[i - 1] == 'J' && s[i + 1] == '?')
                {
                    s[i] = s[i - 1];
                    i++;
                }
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] == 'C' && s[i + 1] == 'C') || (s[i] == 'J' && s[i + 1] == 'J'))
            {
                continue;
            }
            else
            {
                if (s[i] == 'C' && s[i + 1] == 'J')
                {
                    ans += x;
                }
                else if (s[i] == 'J' && s[i + 1] == 'C')
                {
                    ans += y;
                }
            }
        }
        //cout << s << endl;
        if (flag == false)
        {
            cout << ans << "\n";
        }
    }
}