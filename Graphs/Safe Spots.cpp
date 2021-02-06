class Solution
{
public:
    using vvi = vector<vector<int>>;
    using usi = unordered_set<int>;

    usi cycle_nodes;
    usi safe_nodes;
    bool dfs(const vvi &g, int i, usi visited_nodes)
    {

        if (safe_nodes.find(i) != safe_nodes.end())
        {
            return true;
        }
        if (cycle_nodes.find(i) != cycle_nodes.end())
        {
            return false;
        }

        if (visited_nodes.find(i) != visited_nodes.end())
        {
            cycle_nodes.insert(i);
            return false;
        }

        visited_nodes.insert(i);

        for (int child : g[i])
        {
            if (!dfs(g, child, visited_nodes))
            {
                cycle_nodes.insert(i);
                return false;
            }
        }
        safe_nodes.insert(i);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        vector<int> ans;

        usi visited_nodes;

        for (int i = 0; i < graph.size(); i++)
        {
            if (dfs(graph, i, visited_nodes))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
https://leetcode.com/problems/find-eventual-safe-states/