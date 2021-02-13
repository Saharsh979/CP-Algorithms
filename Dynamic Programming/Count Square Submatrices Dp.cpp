class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int dp[matrix.size()][matrix[0].size()];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0 || j==0){
                    dp[i][j]=matrix[i][j];
                }else{
                    if(matrix[i][j]==0){
                        continue;
                    }
                    dp[i][j]=matrix[i][j]+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
               
            }
        }
        
        int ans=0;
                                           
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cout<<dp[i][j]<<" ";
                
                ans+=dp[i][j];
            }
            cout<<endl;
        }
        
    return ans;
        
    }
};

//https://leetcode.com/problems/count-square-submatrices-with-all-ones/