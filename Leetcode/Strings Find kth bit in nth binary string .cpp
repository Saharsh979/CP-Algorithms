class Solution {
public:
    string invert(string s){
        string result="";
        for(int i = 0;i<s.length();i++){
            result.push_back((s[i]=='0')? '1':'0');
        }
        return result;
    }
    char findKthBit(int n, int k) {
        string orignal="0";
        string curr="";
        if(n==1){
            return '0';
        }
        for(int i=2;i<=n;i++){
            string  newstr= invert(orignal);
            reverse(newstr.begin(),newstr.end());
            curr=orignal+"1"+newstr;
            orignal=curr;
        }
        return orignal[k-1];
    }
};

//https://leetcode.com/problems/find-kth-bit-in-nth-binary-string/