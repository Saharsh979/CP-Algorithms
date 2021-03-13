class Solution {
public:
    bool checkpalin(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }else{
                string string1= s.substr(0,i) + s.substr(i+1,s.length());
                string string2= s.substr(0,j) + s.substr(j+1,s.length());
                cout<<string1<<" "<<string2<<endl;
                bool flag1= checkpalin(string1);
                bool flag2= checkpalin(string2);
                if(flag1 || flag2){
                    return true;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

//https://leetcode.com/problems/valid-palindrome-ii/