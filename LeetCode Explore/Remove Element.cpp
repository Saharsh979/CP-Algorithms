class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int count=0;
        int j=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=val){
                nums[j]=nums[i];
                j++;
                i++;
            }else{
                i++;
            }
        }
        return j;
    }
};