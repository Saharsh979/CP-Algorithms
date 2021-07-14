class StockSpanner
{
public:
    stack<pair<int, int>> s;
    int index = 0;
    StockSpanner()
    {
    }

    int next(int price)
    {

        if (s.empty())
        {
            s.push({price, index++});
            return 1;
        }
        else
        {
            while (!s.empty() && s.top().first <= price)
            {
                s.pop();
            }
            int res = 0;
            if (s.empty())
            {
                res = index + 1;
            }
            else
            {
                res = index - s.top().second;
            }
            s.push({price, index++});
            return res;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */