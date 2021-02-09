class Solution {
public:
    int longestPalindromeSubseq(string s) {
        if(s.empty()){
            return 0;
        }
        
        const int N= s.size();
        
        vector<vector<int>> dp(N, vector<int>(N,0));
        
        for(int i=0;i<N;i++){
            dp[i][i]=1;
        }
        for(int l=1;l<N;l++){
            for(int i=0;i<N-l;i++){
                int j=i+l;
                if((j-i+1)==2){
                    if(s[i]==s[j]){
                        dp[i][j]=2;
                    }else{
                        dp[i][j]=1;
                    }
                }else{
                    if(s[i]==s[j]){
                        dp[i][j]=2+ dp[i+1][j-1];
                    }else{
                        dp[i][j]= max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[0][N-1];
    }
};

https://leetcode.com/problems/longest-palindromic-subsequence/