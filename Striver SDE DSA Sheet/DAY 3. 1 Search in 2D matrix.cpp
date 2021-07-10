class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int i = 0;
        int row = -1;
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        if (matrix[0][0] > target)
        {
            return false;
        }
        for (int i = 0; i < matrix.size(); i++)
        {
            if (matrix[i][0] <= target)
            {
                row = i;
            }
            else
            {
                break;
            }
        }
        bool found = false;
        for (int i = 0; i < matrix[row].size(); i++)
        {
            if (matrix[row][i] == target)
            {
                found = true;
            }
        }
        return found;
    }
};