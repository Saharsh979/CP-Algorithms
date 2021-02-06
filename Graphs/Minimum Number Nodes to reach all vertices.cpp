class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        map<int,int> mp;
        for(int i=0;i<edges.size();i++){
            for(int j=0;j<edges[i].size();j++){
                mp[edges[i][j]]=0;
            }
        }
        for(int i=0;i<edges.size();i++){
            mp[edges[i][1]]++;
        }
        vector<int>result;
        for(auto it: mp){
            if(it.second==0){
                result.push_back(it.first);
            }
        }
        return result;
    }
};

https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/