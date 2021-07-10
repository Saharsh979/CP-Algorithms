class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int count1 = 0;
        int count2 = 0;
        int a = 0;
        int b = 0;
        for (auto i : nums)
        {
            if (a == i)
            {
                count1++;
            }
            else if (b == i)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                a = i;
                count1 = 1;
            }
            else if (count2 == 0)
            {
                b = i;
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for (auto n : nums)
        {
            if (n == a)
            {
                count1++;
            }
            else if (n == b)
            {
                count2++;
            }
        }
        vector<int> res;
        if (count1 > nums.size() / 3)
            res.push_back(a);
        if (count2 > nums.size() / 3)
            res.push_back(b);
        return res;
    }
};