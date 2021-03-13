class Solution {
public:
    int minSteps(string s, string t) {
        
        map<char,int> mp1;
        map<char,int> mp2;
        
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;    
        }
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        int count=0;
        
        for(int i=0;i<26;i++){
            char j= 'a'+i;
            if(mp1[j]){
                if(mp1[j]> mp2[j]){
                    if(mp2[j]){
                        count+= mp1[j]-mp2[j];
                    }else{
                        count+=mp1[j];
                    }
                }
            }
        }
        return count;
    }
};

//https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/