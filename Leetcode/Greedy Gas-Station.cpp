class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
       int sumg=0;
        int sumc=0;
        int start=0;
        int tank=0;
        for(int i=0;i<gas.size();i++){
            sumg+= gas[i];
            sumc+= cost[i];
            tank+= gas[i]-cost[i];
            
            if(tank <0){
                start=i+1;
                tank=0;
            }
        }
        if(sumg<sumc){
            return -1;
        }else{
            return start;
        }
        
    }
};
//https://leetcode.com/problems/gas-station/