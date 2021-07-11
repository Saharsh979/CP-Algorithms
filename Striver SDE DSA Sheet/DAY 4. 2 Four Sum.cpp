class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {

        vector<vector<int>> res;

        if (nums.size() == 0)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int target2 = target - nums[i] - nums[j];

                int left = j + 1;
                int right = n - 1;

                while (left < right)
                {
                    int two_sum = nums[left] + nums[right];

                    if (two_sum < target2)
                    {
                        left++;
                    }
                    else if (two_sum > target2)
                    {
                        right--;
                    }
                    else
                    {
                        vector<int> ans;
                        ans.push_back(nums[i]);
                        ans.push_back(nums[j]);
                        ans.push_back(nums[left]);
                        ans.push_back(nums[right]);
                        res.push_back(ans);

                        while (left < right && nums[left] == ans[2])
                        {
                            left++;
                        }
                        while (left < right && nums[right] == ans[3])
                        {
                            right--;
                        }
                    }
                }
                while (j + 1 < n && nums[j + 1] == nums[j])
                {
                    j++;
                }
            }
            while (i + 1 < n && nums[i + 1] == nums[i])
            {
                i++;
            }
        }
        return res;
    }
};