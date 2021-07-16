class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        if(sum%2!=0){
            return false;
        }else{
            return solve(nums,nums.size()-1,sum/2);
        }    
    }
    bool solve(vector<int>&nums, int n, int target){
        if(target==0){
            return true;
        }
        if(n==0 && target!=0){
            return false;
        }
        if(nums[n-1]>target){
            return solve(nums,n-1,target);
        }
        return solve(nums,n-1,target) || solve(nums,n-1,target-nums[n-1]);
    }
};