class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        stack<pair<int, int>> st;
        st.push(make_pair(intervals[0][0], intervals[0][1]));
        vector<vector<int>> results;
        for (int i = 1; i < intervals.size(); i++)
        {
            int previous_ending = st.top().second;
            if (intervals[i][0] <= previous_ending)
            {
                int starting = min(st.top().first, intervals[i][0]);
                int ending = max(st.top().second, intervals[i][1]);
                st.pop();
                st.push(make_pair(starting, ending));
            }
            else
            {
                vector<int> res;
                res.push_back(st.top().first);
                res.push_back(st.top().second);
                results.push_back(res);
                st.pop();
                st.push(make_pair(intervals[i][0], intervals[i][1]));
            }
        }
        if (!st.empty())
        {
            vector<int> res;
            res.push_back(st.top().first);
            res.push_back(st.top().second);
            results.push_back(res);
        }
        return results;
    }
};