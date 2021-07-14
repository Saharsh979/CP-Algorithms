class Solution
{
public:
    int trap(vector<int> &height)
    {

        if (height.size() == 0)
        {
            return 0;
        }
        int leftmax[height.size()];
        int rightmax[height.size()];

        for (int i = 0; i < height.size(); i++)
        {
            if (i == 0)
            {
                leftmax[i] = -1;
            }
            else
            {
                if (height[i] < height[i - 1])
                {
                    leftmax[i] = max(leftmax[i - 1], height[i - 1]);
                }
                else
                {
                    if (height[i] > leftmax[i - 1])
                    {
                        leftmax[i] = -1;
                    }
                    else
                    {
                        leftmax[i] = leftmax[i - 1];
                    }
                }
            }
        }

        for (int i = height.size() - 1; i >= 0; i--)
        {
            if (i == height.size() - 1)
            {
                rightmax[i] = -1;
            }
            else
            {
                if (height[i] < height[i + 1])
                {
                    rightmax[i] = max(rightmax[i + 1], height[i + 1]);
                }
                else
                {
                    if (height[i] > rightmax[i + 1])
                    {
                        rightmax[i] = -1;
                    }
                    else
                    {
                        rightmax[i] = rightmax[i + 1];
                    }
                }
            }
        }

        for (int i = 0; i < height.size() - 1; i++)
        {
            cout << leftmax[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < height.size() - 1; i++)
        {
            cout << rightmax[i] << " ";
        }
        cout << endl;
        int answer = 0;

        for (int i = 0; i < height.size() - 1; i++)
        {
            int val = (min(leftmax[i], rightmax[i]) - height[i]);
            if (val > 0)
            {
                answer += val;
            }
            cout << val << endl;
        }

        return answer;
    }
};