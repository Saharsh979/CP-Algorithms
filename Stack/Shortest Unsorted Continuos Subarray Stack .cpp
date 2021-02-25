class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int nextsmaller[nums.size()];
        int previousgreater[nums.size()];
        
        for(int i=0;i<nums.size();i++){
            nextsmaller[i]=0;
            previousgreater[i]=0;
        }
        stack<int> s1;
        stack<int> s2;
        for(int i=0;i<nums.size();i++){
            while(!s1.empty() && nums[s1.top()] > nums[i]){
                int index=s1.top();
                s1.pop();
                if(nums[i]==0){
                    nextsmaller[index]=nums[i]+1;
                }else{
                    nextsmaller[index]=nums[i];
                }
            }
            s1.push(i);
        }
        
        for(int i=nums.size()-1;i>=0;i--){
            while(!s2.empty() && nums[s2.top()] < nums[i]){
                int index= s2.top();
                s2.pop();
                if(nums[i]==0){
                    previousgreater[index]= nums[i]+1;
                }
                else{
                    previousgreater[index]=nums[i];
                }
            }
            s2.push(i);
        }
        
        int left=-1;
        int right=-1;     
        for(int i=0;i<nums.size();i++){
            cout<<nextsmaller[i]<<" "<<previousgreater[i]<<endl;
        }
        for(int i=0;i<nums.size();i++){
            if(nextsmaller[i]==0){
                left=i;
                continue;
            }else{
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(previousgreater[i]==0){
                right=i;
                continue;
            }else{
                break;
            }
        }
        
        
        if(left==-1 && right == -1){
            return nums.size();
        }   
        else if(left==-1 && right!=-1){
            return right;
        }else if(left!=-1 && right==-1){
            int ans= nums.size()-left-1;
            return ans;
        }
        else if(left>=right){
            return 0;
        }
        else{
            int ans= right-left-1;
            return ans;
        }
    }
};

//https://leetcode.com/problems/shortest-unsorted-continuous-subarray/