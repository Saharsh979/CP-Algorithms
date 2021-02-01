class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        map<int,int>mp;
        map<int,int>pos;
        
        for(int i=0;i<numbers.size();i++){
            mp[numbers[i]]=1;
            pos[numbers[i]]=i;
        }
        vector<int>results;
        
        for(int i=0;i<numbers.size();i++){
            int val=numbers[i];
            if(mp[target-numbers[i]]==1){
                int answer1=i+1;
                int answer2=pos[target-numbers[i]]+1;
                results.push_back(answer1);
                results.push_back(answer2);
                break;
            }else{
                continue;
            }
        }
        return results;
    }
};