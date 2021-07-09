class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> mp;
        int i = 0;
        for (i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
            if (mp[nums[i]] > 1)
            {
                break;
            }
        }
        return nums[i];
    }
};