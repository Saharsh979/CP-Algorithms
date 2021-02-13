class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        int dp[amount+1];
        
        dp[0]=0;
        
        for(int i=1;i<=amount;i++)
        {
            dp[i]=10000;
        }
        for(int i=1;i<=amount;i++){   
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                    int temp=dp[i-coins[j]];
                    temp+=1;
                    if(temp!= 10000 && temp < dp[i]){
                        dp[i] = temp;
                    }
                }
            }
        }
        if(dp[amount]==10000){
            return -1;
        }
        return dp[amount];
    }
};


//https://leetcode.com/problems/coin-change/