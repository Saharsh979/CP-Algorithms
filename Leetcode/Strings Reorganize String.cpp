class Solution {
public:
  
    string reorganizeString(string S) {
        
        string res="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto it: S){
            mp[it]++;
        }
        for(auto it: mp){
            pq.push(make_pair(it.second,it.first));
        }
        
        while(pq.size()>1){
            auto value1=pq.top();
            pq.pop();
            auto value2=pq.top();
            pq.pop();
            res.push_back(value1.second);
            res.push_back(value2.second);
            value1.first=value1.first-1;
            value2.first=value2.first-1;
            if(value1.first){
                pq.push(value1);
            }
            if(value2.first){
                pq.push(value2);
            }
        }
            if(!pq.empty()){
                if(pq.top().first>1){
                    return "";
                }else{
                    res.push_back(pq.top().second);
                }
            }
       
    
        return res;
    }
};

//https://leetcode.com/problems/reorganize-string/