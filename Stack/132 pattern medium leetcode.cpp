class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if(nums.size()<3){
            return false;
        }
       stack<int>s;
        int mini[nums.size()];
        mini[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            mini[i]=min(nums[i], mini[i-1]);
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]> mini[i]){
                while(!s.empty() && s.top()<= mini[i]){
                    s.pop();
                }
                if(!s.empty() && s.top()< nums[i]){
                    return true;
                }
                s.push(nums[i]);
            }
        }
        return false;
    }
};