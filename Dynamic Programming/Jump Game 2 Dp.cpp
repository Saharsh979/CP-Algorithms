class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) 
            return 0;
        int ans=1;
        int max_reachable_index=0+nums[0];
        int cur=nums[0];
        int i=1;
        while(max_reachable_index<nums.size()-1)
        {
           if(i+nums[i]>cur)
           {
               cur=i+nums[i];
           }
          if(i==max_reachable_index)
          {
              max_reachable_index=cur;
              ans++;
          }
            i++;
        }
        return ans;
    }
};

https://leetcode.com/problems/jump-game-ii/
