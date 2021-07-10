class Solution
{
public:
    int count;

    void checkcount(vector<int> &nums, int left, int mid, int right)
    {
        int l = left;
        int r = mid + 1;
        while (l <= mid && r <= right)
        {
            if ((long)nums[l] > (long)2 * nums[r])
            {
                count += (mid - l + 1);
                r++;
            }
            else
            {
                l++;
            }
        }
        sort(nums.begin() + left, nums.begin() + right + 1);
        return;
    }
    void mergesort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = (left + right) / 2;
        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);

        checkcount(nums, left, mid, right);
        return;
    }
    int reversePairs(vector<int> &nums)
    {
        if (!nums.size())
        {
            return 0;
        }

        count = 0;
        mergesort(nums, 0, nums.size() - 1);
        return count;
    }
};