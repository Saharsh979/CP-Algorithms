class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &result, vector<int> path, int source, int destination){
        path.push_back(source);
        if(source==destination){
            result.push_back(path);
            return ;
        }
        for(auto child: graph[source]){
            dfs(graph, result,path,child,destination);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>paths;
        vector<int>path;
        
        int nodes=graph.size();
        if(nodes==0){
            return paths;
        }
        dfs(graph,paths,path,0,nodes-1);
        return paths;
        
    }
};

https://leetcode.com/problems/all-paths-from-source-to-target/