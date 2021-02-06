class Solution
{
public:
    vector<int> adj[110];
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        map<int, int> network;
        for (auto it : roads)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            network[it[0]]++;
            network[it[1]]++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                std::vector<int>::iterator it;
                it = find(adj[i].begin(), adj[i].end(), j);
                if (it != adj[i].end())
                {
                    ans = max(ans, (network[i] + network[j] - 1));
                }
                else
                {
                    ans = max(ans, (network[i] + network[j]));
                }
            }
        }
        return ans;
    }
};