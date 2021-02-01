class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        if(nums.size()==0){
            return -1;
        }
        int n=int(nums.size());
        int pre[int(nums.size())];
        int suf[int(nums.size())];
        pre[0]=nums[0];
        for(int i=1;i<n;i++){
            pre[i]=nums[i]+pre[i-1];
        }
        suf[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
            suf[j]=nums[j]+suf[j+1];
        }
        
        for(int i=0;i<n;i++){
            if(pre[i]==suf[i]){
                return i;
            }
        }
        return -1;
    }
    
    
};