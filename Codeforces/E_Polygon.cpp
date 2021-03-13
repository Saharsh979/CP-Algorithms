class Solution
{
public:
    void recurse(vector<string> &v, string s, int n, int m)
    {
        if(n==0 && m==0){
            v.push_back(s);
            return;
        }
        if(m>0){
            recurse(str+")", n,m-1);
        }
        if(n>0){
            recurse(str+"(",n-1,m+1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        vector<strng> res;
        recurse(res, "", n,0);
        return res;
    }
};