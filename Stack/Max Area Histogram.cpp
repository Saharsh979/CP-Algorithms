
int ret = 0;
height.push_back(0);
vector<int> index;

for (int i = 0; i < height.size(); i++)
{
    while (index.size() > 0 && height[index.back()] >= height[i])
    {
        int h = height[index.back()];
        index.pop_back();

        int sidx = index.size() > 0 ? index.back() : -1;
        if (h * (i - sidx - 1) > ret)
            ret = h * (i - sidx - 1);
    }
    index.push_back(i);
}

return ret;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {

        stack<int> s1;
        stack<int> s2;
        int nsl[height.size()];
        int nsr[height.size()];
        for (int i = 0; i < height.size(); i++)
        {
            nsl[i] = nsr[i] = 0;
        }
        for (int i = 0; i < height.size(); i++)
        {
            while (!s1.empty() && height[s1.top()] >= height[i])
            {
                nsr[s1.top()] = i;
                s1.pop();
            }
            if (!s1.empty())
            {
                nsl[i] = s1.top();
            }
            else
            {
                nsl[i] = -1;
            }
            s1.push(i);
        }
        while (!s1.empty())
        {
            nsr[s1.top()] = height.size();
            s1.pop();
        }
        int area[height.size()];
        int max_val = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int val = height[i] * (nsr[i] - nsl[i] + 1) - 2 * height[i];
            max_val = max(max_val, val);
            cout << val << endl;
        }
        return max_val;
    }
};