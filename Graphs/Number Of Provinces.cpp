class Solution {
public:
    vector<int> ar[201];
    int vis[201];

    void dfs(int node)
    {
        vis[node] = 1;
        for(int child: ar[node])
        {
            if(vis[child] == 0)
                dfs(child);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> a;
        a = isConnected;
        int n = isConnected.size();
        for(int i = 0; i < n; i++)
            for(int j = 0 ; j < a[i].size(); j++)
            {
                if(i == j) continue;
                else if(a[i][j] == 1) ar[i].push_back(j), ar[j].push_back(i); 
            }

        int cc_count = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0)
                dfs(i), cc_count++;
        }
        return cc_count;
    }
};

https://leetcode.com/problems/number-of-provinces