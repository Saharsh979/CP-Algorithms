#include <bits/stdc++.h>
#define ll long long
#define debug cout << "K";

using namespace std;

ll int n, m;
ll int amount = numeric_limits<ll int>::max();
vector<ll int> adj[100001];
bool visited[100001];
ll int cost[100001];
void dfs(ll int node)
{
    visited[node] = true;
    if (cost[node] < amount)
        amount = cost[node];
    for (ll int next : adj[node])
    {
        if (!visited[next])
            dfs(next);
    }
}

int main()
{

    cin >> n >> m;

    ll int ans = 0;
    for (ll int i = 1; i <= n; i++)
        cin >> cost[i];
    for (ll int i = 0; i < m; i++)
    {
        ll int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (ll int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            ans += amount;
            amount = numeric_limits<ll int>::max();
        }
    }
    cout << ans << "\n";

    return 0;
}
