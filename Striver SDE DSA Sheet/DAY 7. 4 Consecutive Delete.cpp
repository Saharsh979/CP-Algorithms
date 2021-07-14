class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }

        int i = 1;
        int j = 1;
        int curr = nums[0];
        while (j < nums.size())
        {
            if (nums[j] == curr)
            {
                j++;
                continue;
            }
            else
            {
                curr = nums[j];
                nums[i++] = curr;
            }
        }
        return i;
    }
};