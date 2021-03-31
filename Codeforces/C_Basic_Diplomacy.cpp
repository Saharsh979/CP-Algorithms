#include <bits/stdc++.h>
using namespace std;
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define fbo find_by_order
#define ook order_of_key
typedef tree<long long int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
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
        long long int n, m;
        cin >> n >> m;
        long long int maxx = (m + 1) / 2;
        vector<long long int> ans(m);
        vector<vector<long long int>> arr(n);
        for (long long int i = 0; i < m; i++)
        {
            long long int temp;
            cin >> temp;
            for (long long int j = 0; j < temp; j++)
            {
                long long int x;
                cin >> x;
                arr[x - 1].push_back(i);
            }
        }
        priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, std::greater<pair<long long int, long long int>>> pq;
        unordered_set<long long int> all;
        for (long long int i = 0; i < m; i++)
            all.insert(i);
        for (long long int i = 0; i < n; i++)
        {
            pq.push(make_pair(arr[i].size(), i));
        }

        long long int M = m;
        bool NO = false;
        while (M > 0 && !pq.empty())
        {
            pair<long long int, long long int> temp = pq.top();
            long long int x = temp.second;
            long long int tempp = 0;
            for (long long int i = 0; i < temp.first; i++)
            {
                long long int y = arr[x][i]; // day
                if (all.find(y) != all.end())
                {
                    ans[y] = x + 1;
                    all.erase(y);
                    tempp++;
                    M--;
                }
                if (tempp == maxx)
                {
                    break;
                }
            }
            pq.pop();
        }
        for (long long int i = 0; i < m; i++)
        {
            if (ans[i] == 0)
            {
                NO = true;
                break;
            }
        }
        if (NO)
        {
            cout << "NO" << endl;
            break;
        }
        cout << "YES" << endl;
        for (long long int i = 0; i < m; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}
