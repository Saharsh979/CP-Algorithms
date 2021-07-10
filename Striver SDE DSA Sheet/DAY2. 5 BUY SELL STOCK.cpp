class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minval = INT_MAX;
        int maxprofit = 0;
        for (auto i : prices)
        {
            minval = min(minval, i);
            maxprofit = max(maxprofit, i - minval);
        }
        return maxprofit;
    }
};