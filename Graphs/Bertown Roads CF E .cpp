

#include <bits/stdc++.h>
using namespace std;

vector<int> ar[1000001];
vector<pair<int, int>> edges;
int inti[1000001];
int vis[1000001];
int low[1000001];
int timer = 0;
bool flag = false;
void dfs(int node, int par)
{
    vis[node] = 1;
    inti[node] = low[node] = timer;
    timer++;
    for (int child : ar[node])
    {
        if (child == par)
            continue;
        if (vis[child] == 1)
        {
            low[node] = min(low[node], inti[child]);
            if (inti[node] > inti[child])
            {
                edges.push_back(make_pair(node, child));
            }
        }
        else
        {
            dfs(child, node);
            if (low[child] > inti[node])
            {
                flag = true;
                return;
            }
            edges.push_back(make_pair(node, child));
            low[node] = min(low[node], low[child]);
        }
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        ar[a].push_back(b);
        ar[b].push_back(a);
    }
    dfs(1, -1);
    if (flag == true)
    {
        cout << 0;
    }
    else
    {
        for (pair<int, int> e : edges)
        {
            cout << e.first << " " << e.second << endl;
        }
    }
}
