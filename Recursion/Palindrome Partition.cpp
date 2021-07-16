class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> path;
        function(0, s, path, res);
        return res;
    }

    void function(int index, string s, vector<string> &path, vector<vector<string>> &res)
    {
        if (index == s.size())
        {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); ++i)
        {
            if (ispalin(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                function(i + 1, s, path, res);
                path.pop_back();
            }
        }
    }
    bool ispalin(string s, int start, int end)
    {
        bool flag = true;
        while (start <= end)
        {
            if (s[start] != s[end])
            {
                flag = false;
                break;
            }
            else
            {
                start++;
                end--;
            }
        }
        return flag;
    }
};