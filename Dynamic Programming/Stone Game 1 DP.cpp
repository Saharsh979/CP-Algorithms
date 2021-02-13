class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
       /* int dp[piles.size()][piles[0].size()];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<piles.size();i++){
            dp[i][i]=piles[i];
        }
        */
        
        int alex=0;
        int lee=0;
        sort(piles.begin(),piles.end());
        int n=piles.size();
        bool flag=true;
        for(int i=0;i<n;i++){
            if(flag){
                alex+=piles[i];
                flag=false;
            }else{
                flag=true;
                lee+=piles[i];
            }
        }
        cout<<alex<<" "<<lee<<endl;
        return alex>lee || lee>alex;
    }
};


class Solution {
public:
    bool stoneGame(vector<int>& a) {
        int n = a.size();
        
        pair<int, int> dp[n][n];
       
        for(int i = 0; i < n; ++i){
            dp[i][i].first = a[i];
            dp[i][i].second = 0;
        }
        for(int turn = 2; turn <= n; ++turn){
        
            for(int i = 0; i <= n - turn; ++i){
                int j = i + turn - 1;
                int pickLeft = a[i] + dp[i+1][j].second, pickRight = a[j] + dp[i][j-1].second;
                dp[i][j].first = max(pickLeft, pickRight);
                if(dp[i][j].first == pickLeft) dp[i][j].second = dp[i+1][j].first;
                else dp[i][j].second = dp[i][j-1].first;
            }
        }
     
        return dp[0][n-1].first > dp[0][n-1].second;
    }
};

//https://leetcode.com/problems/stone-game/