class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxsum = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                maxsum = max(maxsum, sum);
            }
        }
        return maxsum;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = nums[0];
        int maxsum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (sum <= 0)
            {
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};

public
int maxSubArray(int[] A)
{
    int n = A.length;
    int[] dp = new int[n]; //dp[i] means the maximum subarray ending with A[i];
    dp[0] = A[0];
    int max = dp[0];

    for (int i = 1; i < n; i++)
    {
        dp[i] = A[i] + (dp[i - 1] > 0 ? dp[i - 1] : 0);
        max = Math.max(max, dp[i]);
    }

    return max;
}