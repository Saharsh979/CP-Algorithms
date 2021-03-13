class Solution {
public:
    int minFlips(string target) {
        
        int count=0;
        
        int j=0;
        if(target[0]=='1'){
            count++;
        }
        while(j<target.length()-1){
            if(target[j+1]=='1' && target[j]=='1'|| target[j+1]=='0' && target[j]=='0'){
                j++;
                continue;
            }else{
                j++;
                count++;
            }
        }
        return count;
    }
};

//https://leetcode.com/problems/bulb-switcher-iv/