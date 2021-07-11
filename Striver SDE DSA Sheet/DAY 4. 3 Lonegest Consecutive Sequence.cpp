class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        map<int, int> mp;
        int counter = 0;
        int answer = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            value[nums[i]] = 0;
            mp[nums[i]]++;
        }
        map<int, int> value;
        int i = 0;
        while (i < nums.size())
        {
            if (mp.find(nums[i] - 1) != mp.end())
            {
                i++;
                continue;
            }
            else
            {
                bool flag = true;
                int count = 1;
                int value = nums[i] + 1;
                while (mp.find(value) != mp.end())
                {
                    count++;
                    value++;
                }
                answer = max(answer, count);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            cout << value[nums[i]] << " ";
        }
        return answer;
    }
};