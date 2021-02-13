class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n = coins.size();
        int dp[amount+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0; i<coins.size(); i++)
        {
            for(int j = coins[i]; j<=amount; j++)
            {
                dp[j]+=dp[j-coins[i]];
            }
        }
        
        return dp[amount];
    }
};

//https://leetcode.com/problems/coin-change-2/