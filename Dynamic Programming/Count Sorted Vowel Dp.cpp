class Solution {
public:
    int countVowelStrings(int n) {
        int a = 1;
        int e = 1;
        int i = 1;
        int o = 1;
        int u = 1;
        
        while (--n){
            e += a;
            i += e;
            o += i;
            u += o;         
        }
        return a + e + i + o + u;
    }
};


class Solution {
public:
    
    int countVowelStrings(int n) {
        if(n==0)
            return 0;
        vector<vector<int> > dp(n+1,vector<int> (5,0));
        for(int i=0;i<5;i++){
            dp[1][i]=1;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<=j;k++)
                    dp[i][j]+=dp[i-1][k];
            }
        }
        int ans=0;
        for(int i=0;i<5;i++){
            ans+=dp[n][i];
        }
        return ans;
    }
};

https://leetcode.com/problems/count-sorted-vowel-strings/