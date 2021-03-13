class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize)
 {
    int i = 0, j = 0, unique = 0, res = 0, cnt[26] = {};
    unordered_map<string, int> m;
    while (j < s.size())
    {
        if (++cnt[s[j++] - 'a'] == 1){
            ++unique;
        }
        while (unique > maxLetters || j - i > minSize){
            if (--cnt[s[i++] - 'a'] == 0){
                --unique;
            }
        }
        if (j - i == minSize){
            res = max(res, ++m[s.substr(i, minSize)]);
        }
    }
    return res;
 } 
    
};

//https://leetcode.com/problems/maximum-number-of-occurrences-of-a-substring/