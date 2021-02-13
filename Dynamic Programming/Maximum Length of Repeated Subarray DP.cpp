class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n= A.size();
        int m= B.size();
        
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                if(A[i]==B[j]){
                    if(i==0 || j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=dp[i-1][j-1]+1;
                    }
                }
            }
        }
        int maxval=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]>maxval)
                {
                    maxval=dp[i][j];
                }
            }
        }
        return maxval;
    }
};

https://leetcode.com/problems/maximum-length-of-repeated-subarray/