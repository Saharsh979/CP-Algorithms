class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        vector<int> results;
        if (matrix.size() == 0 || matrix[0].size() == 0)
        {
            return results;
        }

        bool flag = true;
        int row = 0;
        int col = 0;

        while (row < matrix.size() && col < matrix[0].size())
        {

            results.push_back(matrix[row][col]);

            int newr = row + (flag == true ? -1 : 1);
            int newc = col + (flag == true ? 1 : -1);

            if (newr < 0 || newr == matrix.size() || newc < 0 || newc == matrix[0].size())
            {
                if (flag == true)
                {
                    row += (col == matrix[0].size() - 1 ? 1 : 0);
                    col += (col < matrix[0].size() - 1 ? 1 : 0);
                }
                else
                {
                    col += (row == matrix.size() - 1 ? 1 : 0);
                    row += (row < matrix.size() - 1 ? 1 : 0);
                }

                flag = !flag;
            }
            else
            {
                row = newr;
                col = newc;
            }
        }
        return results;
    }
};