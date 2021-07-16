class Solution
{
public:
    void function(vector<int> &candidates, set<vector<int>> &s, vector<int> &ans, int i, int n, int currsum, int target)
    {
        if (currsum > target)
        {
            return;
        }
        if (currsum == target)
        {
            if (s.find(ans) == s.end())
            {
                s.insert(ans);
            }
            else
            {
                return;
            }
        }
        if (i > n)
        {
            return;
        }
        function(candidates, s, ans, i + 1, candidates.size() - 1, currsum, target);
        ans.push_back(candidates[i]);
        function(candidates, s, ans, i + 1, candidates.size() - 1, currsum + candidates[i], target);
        ans.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {

        sort(candidates.begin(), candidates.end());
        set<vector<int>> s;
        vector<int> ans;
        vector<vector<int>> res;
        function(candidates, s, ans, 0, candidates.size() - 1, 0, target);
        for (auto sum : s)
        {
            res.push_back(sum);
        }
        return res;
    }
};