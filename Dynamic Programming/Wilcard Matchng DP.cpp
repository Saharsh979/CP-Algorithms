class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int n=s.size(), m=p.size();
        if(n==0 && m==0) return true;
        if(m==0) return false;
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        int star=0, ques=0;
        for(int i=0; i<m; i++)
        {
            if(p[i]=='*') star++;
            if(p[i]=='?') ques++;
        }
        if(star==m) return true;
        if(ques==m && n==m) return true;
        for(int i=0; i<=n; i++) dp[i][0] = false;
        dp[0][0] = true;
        for(int j=1; j<m; j++) dp[0][j] = p[j-1]=='*' && dp[0][j-1];
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(p[j-1]>='a' && p[j-1]<='z') dp[i][j] = dp[i-1][j-1] && (bool)(s[i-1]==p[j-1]);
                else if(p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};

https://leetcode.com/problems/wildcard-matching/