class Solution
{
public:
    int vis[2010];
    int col[2010];
    vector<int> adj[2010];
    bool dfs(int v, int c)
    {
        vis[v] = 1;
        col[v] = c;

        for (int child : adj[v])
        {
            if (vis[child] == 0)
            {
                if (dfs(child, c ^ 1) == false)
                {
                    return false;
                }
            }
            else
            {
                if (col[v] == col[child])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {

        for (auto dislike : dislikes)
        {
            adj[dislike[0]].push_back(dislike[1]);
            adj[dislike[1]].push_back(dislike[0]);
        }

        for (int i = 1; i <= N; i++)
        {
            if (vis[i] == 0 && !dfs(i, 1))
                return false;
        }
        return true;
    }
};

https://leetcode.com/problems/possible-bipartition/