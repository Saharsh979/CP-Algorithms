class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        
        
        vector<int> nextgreater(T.size());
        for(int i=0;i<T.size();i++){
            nextgreater[i]=0;
        }
        
        stack<int> st;
        
        for(int i=0;i<T.size();i++){
            while(!st.empty() && T[st.top()]<T[i]){
                int index= st.top();
                nextgreater[index]=i-index;
                st.pop();
            }
            st.push(i);
        }
        
        return nextgreater;
    }
    
};

https://leetcode.com/problems/daily-temperatures/