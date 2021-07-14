class Solution
{
public:
    int findmha(int res[], int size)
    {
        stack<int> s;
        int nsr[size];
        int nsl[size];
        int answer = 0;

        for (int i = 0; i < size; i++)
        {
            while (!s.empty() && res[s.top()] >= res[i])
            {
                nsr[s.top()] = i;
                s.pop();
            }
            if (s.empty())
            {
                nsl[i] = -1;
            }
            else
            {
                nsl[i] = s.top();
            }
            s.push(i);
        }
        while (!s.empty())
        {
            nsr[s.top()] = size;
            s.pop();
        }
        for (int i = 0; i < size; i++)
        {
            int val = res[i] * (nsr[i] - nsl[i] - 1);
            answer = max(answer, val);
        }
        return answer;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if (matrix.size() == 0)
        {
            return 0;
        }
        int res[matrix[0].size()];
        int ans = 0;
        for (int i = 0; i < matrix[0].size(); i++)
        {
            res[i] = 0;
        }
        int size = matrix[0].size();
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '0')
                {
                    res[j] = 0;
                }
                else
                {
                    res[j] += 1;
                }
            }
            for (int i = 0; i < size; i++)
            {
                cout << res[i] << " ";
            }
            cout << endl;
            ans = max(ans, findmha(res, size));
        }
        return ans;
    }
};