class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxval = 0;
        int count = 0;
        int i = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
                maxval = max(maxval, count);
            }
            else
            {
                count = 0;
            }
        }
        return maxval;
    }
};