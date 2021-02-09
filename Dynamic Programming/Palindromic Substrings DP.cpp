class Solution {
public:
    int countSubstrings(string s) {
        if(s.size()==0){
            return 0;
        }
        int n=s.size();
        int table[n][n];
        memset(table,0,sizeof(table));
        
        for(int i=0;i<n;i++){
            table[i][i]=1;
        }
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                table[i][i+1]=1;
            }
        }
        for(int k=3;k<=n;k++){
            for(int i=0;i<=n-k;i++){
                int j=i+k-1;
                if(table[i+1][j-1]==1 && s[i]==s[j]){
                    table[i][j]=1;
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(table[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
https://leetcode.com/problems/palindromic-substrings/