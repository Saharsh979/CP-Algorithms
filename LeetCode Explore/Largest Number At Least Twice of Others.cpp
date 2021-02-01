class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index;
        int maxvalue=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxvalue){
                maxvalue=nums[i];
                index=i;
            }
        }
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        int maxval=nums[0];
        bool flag=true;
        for(int i=1;i<int(nums.size());i++){
            if(nums[i]*2<=maxval){
                continue;
            }else{
                flag=false;
                break;
            }
        }
        if(flag==false){
            return -1;
        }else{
            return index;
        }
        
    }
};