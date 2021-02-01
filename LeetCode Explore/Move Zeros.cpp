class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        vector<int> nonzero;
        int count=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                count++;
            }else{
                nonzero.push_back(nums[i]);
            }
        }
        while(count>0){
            nonzero.push_back(0);
            count--;
        }
        
        for(int i=0;i<nums.size();i++){
            nums[i]=nonzero[i];
        }
    }
};