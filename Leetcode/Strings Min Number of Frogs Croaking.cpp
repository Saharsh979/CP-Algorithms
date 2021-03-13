class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        
        map<char,int> mp;
         map<char,int> curr;
        
        for(int i=0;i<croakOfFrogs.length();i++){
            mp[croakOfFrogs[i]]++;
            curr[croakOfFrogs[i]]=-1;
        }
        int count=0;
        for(int i=0;i<croakOfFrogs.length();i++){
            if(croakOfFrogs[i]=='c'){
                count++;
            }
        }
        for(auto it: mp){
            if(it.second != count){
                return -1;
            }
        }
        int maxcount=0;
        int countt=0;
        
        for(int i=0;i<croakOfFrogs.length();i++){
            if(croakOfFrogs[i]=='c'){
                countt++;
                maxcount=max(maxcount,countt);
            }
            
            else if(croakOfFrogs[i]=='k'){
                countt--;
            }
            else if(countt==0){
                return -1;
            }
            if(countt<0){
                return -1;
            }
        }
        return maxcount;    
    }
};

//https://leetcode.com/problems/minimum-number-of-frogs-croaking/