class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> xaxis;
        set<int> yaxis;

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    xaxis.insert(i);
                    yaxis.insert(j);
                }
            }
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (xaxis.find(i) != xaxis.end() || yaxis.find(j) != yaxis.end())
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};