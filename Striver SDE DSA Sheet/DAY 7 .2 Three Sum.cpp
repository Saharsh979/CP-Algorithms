class Solution
{
public:
    std::tuple<int, int, int> triple;
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> answer;
        map<int, int> freq;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
        }
        set<tuple<int, int, int>> s;

        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]--;
            for (int j = i + 1; j < nums.size(); j++)
            {
                vector<int> res;
                freq[nums[j]]--;
                if (freq[-nums[i] - nums[j]])
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                    res.push_back(-nums[i] - nums[j]);
                    sort(res.begin(), res.end());
                    s.insert(make_tuple(res[0], res[1], res[2]));
                }
                freq[nums[j]]++;
            }
            freq[nums[i]]++;
        }

        for (auto it : s)
        {
            vector<int> results;
            results.push_back(get<0>(it));
            results.push_back(get<1>(it));
            results.push_back(get<2>(it));
            answer.push_back(results);
        }

        return answer;
    }
};

//Better Solution

class Solution
{
public:
    std::tuple<int, int, int> triple;
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        map<pair<int, int>, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = -nums[i];
            int low = i + 1;
            int high = nums.size() - 1;

            while (low < high)
            {
                vector<int> res;
                int val = nums[low] + nums[high];
                if (val == x)
                {
                    if (freq[make_pair(nums[low], nums[high])] == 0)
                    {
                        res.push_back(nums[i]);
                        res.push_back(nums[low]);
                        res.push_back(nums[high]);
                        results.push_back(res);
                        freq[make_pair(nums[low], nums[high])]++;
                    }
                }
                if (val > x)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }
        }
        return results;
    }
};