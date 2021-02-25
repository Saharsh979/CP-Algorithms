class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        int nextgreater[nums2.size()];
        stack<int> s1;
        map<int,int> mp;
        
        for(int i=0;i<nums2.size();i++)
        {
            while(!s1.empty() && nums2[s1.top()]< nums2[i]){
                int index= s1.top();
                s1.pop();
                nextgreater[index]=nums2[i];
                mp[nums2[index]]= nums2[i];
            } 
            s1.push(i);
        }
        vector<int>res;
        
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
                res.push_back(mp[nums1[i]]);
            }else{
                res.push_back(-1);
            }
        }
        return res;
    }
    
};

//https://leetcode.com/problems/next-greater-element-i/