#include <bits/stdc++.h>
#define int long long int
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
const int MOD = 1e9 + 7;
const int LOG = 19;
const int INF = 1e18;
const double PI = acos(-1);
const double EPS = 1e-9;
const int N = 3e5 + 5;

struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
        else
        {
            return a.second < b.second;
        }
    };
};

signed main()
{
    int n;
    cin >> n;
    map<int, int> count_numbers;
    int min_val = INF;
    int max_val = -INF;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count_numbers[x]++;
    }
    set<pair<int, int>, cmp> q;
    for (auto &x : count_numbers)
    {
        q.insert({x.second, x.first});
    }
    int ans = 0;
    while (q.size())
    {
        pair<int, int> b = *q.begin();
        q.erase(q.begin());
        max_val = max(max_val, b.second);
        min_val = min(min_val, b.second);
        ans += (max_val - min_val) * b.first;
    }
    cout << ans << endl;
}