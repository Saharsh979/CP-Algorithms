class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int step=nums[0];
      for(int i=1;i<nums.size();i++){
          if(step==0){
              if(nums.size()==1){
                  return true;
              }else{
                  return false;
              }
          }
          step=step-1;
          if(step<nums[i]){
              step=nums[i];
          }
      }
       return true;
    }
};

https://leetcode.com/problems/jump-game/