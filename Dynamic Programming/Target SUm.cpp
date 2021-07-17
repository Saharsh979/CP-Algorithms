class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return backtrack(nums, 0, 0, target);
    }
    int backtrack(vector<int> &nums, int index, int sum, int target)
    {
        if (index == nums.size())
        {
            if (sum == target)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        return backtrack(nums, index + 1, sum + nums[index], target) + backtrack(nums, index + 1, sum - nums[index], target);
    }
};