class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int c1 = 0, c2 = 0, c0 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                c0++;
            }
            else if (nums[i] == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }
        int counter = 0;
        while (c0--)
        {
            nums[counter] = 0;
            counter++;
        }
        while (c1--)
        {
            nums[counter] = 1;
            counter++;
        }
        while (c2--)
        {
            nums[counter] = 2;
            counter++;
        }
    }
};

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0;
        int i = 0;
        int high = nums.size() - 1;

        while (i <= high)
        {
            if (nums[i] < 1)
            {
                swap(nums[i], nums[low]);
                i++;
                low++;
            }
            else if (nums[i] > 1)
            {
                swap(nums[i], nums[high]);
                high--;
            }
            else
            {
                i++;
            }
        }
    }
};