class Solution
{
public:
    int minMalwareSpread(vector<vector<int>> &graph, vector<int> &initial)
    {
        int ans = 0, n = initial.size(), minCnt = graph.size();
        sort(initial.begin(), initial.end());
        for (int i : initial)
        {
            int cnt = bfs(graph, initial, i);
            if (cnt < minCnt)
                minCnt = cnt, ans = i;
        }
        return ans;
    }

private:
    int bfs(vector<vector<int>> &graph, vector<int> &initial, int node)
    {
        queue<int> q;
        unordered_set<int> st = {node};
        int cnt = 0;
        for (int i : initial)
            if (i != node)
                q.push(i);
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            if (st.count(cur))
                continue;
            st.insert(cur);
            cnt++;
            for (int i = 0; i < graph.size(); i++)
                if (i != cur && graph[cur][i])
                    q.push(i);
        }
        return cnt;
    }
};