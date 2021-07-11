class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;
        int ans1, ans2;
        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];

            if (mp.find(val) != mp.end() && mp[val] != i)
            {
                ans1 = i;
                ans2 = mp[val];
                break;
            }
        }

        vector<int> res;
        res.push_back(ans1);
        res.push_back(ans2);

        return res;
    }
};