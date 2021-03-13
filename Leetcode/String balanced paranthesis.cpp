class Solution
{
public:
   
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        recurse(res, "", n,0);
        return res;
    }
    
     void recurse(vector<string> &v, string s, int n, int m)
    {
        if(n==0 && m==0){
            v.push_back(s);
            return;
        }
        if(m>0){
            recurse(v,s+")", n,m-1);
        }
        if(n>0){
            recurse(v,s+"(",n-1,m+1);
        }
    }
};

//https://leetcode.com/problems/generate-parentheses/