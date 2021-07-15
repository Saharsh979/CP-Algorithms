class Solution
{
public:
    vector<vector<int>> result;
    vector<int> current;
    int sum;
    void function(vector<int> &candidates, int target, int index)
    {
        if (sum > target)
        {
            return;
        }
        if (sum == target)
        {
            result.push_back(current);
        }
        for (int i = index; i < candidates.size(); i++)
        {
            sum += candidates[i];
            current.push_back(candidates[i]);
            function(candidates, target, i);
            sum = sum - candidates[i];
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        sum = 0;
        function(candidates, target, 0);
        return result;
    }
};

class Solution
{
public:
    void solve(vector<int> &candidates, vector<vector<int>> &res, vector<int> &ans, int index, int size, int curr_sum, int target)
    {
        if (curr_sum == target)
        {
            res.push_back(ans);
            return;
        }
        else if (curr_sum > target || i > size - 1)
        {
            return;
        }
        else
        {
            ans.push_back(candidates[index]);
            solve(candidates, res, ans, index, size, curr_sum + candidates[index], target);
            solve(candidates, res, ans, index + 1, size, curr_sum + candidates[index], target);
            ans.pop_back();
            solve(candidates, res, ans, index + 1, size, curr_sum, target);
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        vector<vector<int>> res;
        int size = candidates.size();
        vector<int> ans;
        solve(candidates, res, ans, 0, size, 0, target);
        return res;
    }
};