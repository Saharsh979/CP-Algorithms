class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        else
        {
            return solve(nums, nums.size() - 1, sum / 2);
        }
    }
    bool solve(vector<int> &nums, int n, int target)
    {
        if (target == 0)
        {
            return true;
        }
        if (n == 0 && target != 0)
        {
            return false;
        }
        if (nums[n - 1] > target)
        {
            return solve(nums, n - 1, target);
        }
        return solve(nums, n - 1, target) || solve(nums, n - 1, target - nums[n - 1]);
    }
};

[38, 7, 20, 83, 13, 44, 87, 70, 45, 54, 23, 72, 81, 62, 33, 55, 16, 96, 9, 64, 15, 88, 45, 97, 43, 55, 56, 43, 13, 29, 79, 27, 26, 50, 25, 5, 24, 61, 48, 32, 52, 62, 25, 77, 18, 4, 59, 73, 70, 92, 2, 36, 94, 4, 24, 71, 42, 11, 41, 94, 20, 82, 14, 71, 45, 80, 35, 61, 31, 61, 46, 47, 40, 80, 52, 90, 52, 6, 75, 28, 67, 68, 8, 77, 19, 2, 85, 69, 35, 14, 58, 67, 45, 66, 87, 6, 24, 88, 11, 24]

    class Solution
{
public:
    bool canPartition(vector<int> & nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        if (sum % 2 != 0)
        {
            return false;
        }
        else
        {
            set<int> dp;
            dp.insert(0);
            int target = sum / 2;

            for (int i = 0; i < nums.size(); i++)
            {
                set<int> nextdp;
                for (int x : dp)
                {
                    if (x + nums[i] == target)
                    {
                        return true;
                    }
                    nextdp.insert(x + nums[i]);
                    nextdp.insert(x);
                }
                dp = nextdp;
            }

            if (dp.find(target) != dp.end())
            {
                return true;
            }
        }
        return false;
    }
};