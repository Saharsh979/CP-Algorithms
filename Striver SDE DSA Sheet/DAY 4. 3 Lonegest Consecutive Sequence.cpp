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
                int count = 1;
                int value = nums[i] + 1;
                while (mp.find(value) != mp.end())
                {
                    count++;
                    value++;
                }
                answer = max(answer, count);
                i++;
            }
        }
        return answer;
    }
};

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(begin(nums), end(nums));
        int longest = 0;
        for (auto &num : s)
        {
            if (s.count(num - 1))
                continue;
            int j = 1;
            while (s.count(num + j))
                j++;
            longest = max(longest, j);
        }
        return longest;
    }
};