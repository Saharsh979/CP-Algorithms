class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }        
        int start=0;
        int end=0;
        int currsum=0;
        int mini=nums.size()+1;
        while(end<nums.size()){
               
            while(currsum<s && end<nums.size()){
                currsum+=nums[end++];
            }
            
            while(currsum>=s && start<end){
                int length=end-start;
                if(length<mini){
                    mini=length;
                }
                currsum-=nums[start];
                start++;
            }
        }
        if(mini==nums.size()+1){
            return 0;
        }else{
            return mini;
        }
        
        
    }
};