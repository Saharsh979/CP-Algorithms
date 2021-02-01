class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        int rowSize = matrix.size();
        if (rowSize == 0)
            return res;
        int colSize = matrix[0].size();
        int lb = 0, rb = colSize - 1, ub = 0, db = rowSize - 1; // left bound, right bound, up bound, down bound;
        int direction = 0;
        int col = 0, row = 0;
        while (lb <= rb && ub <= db)
        {
            res.push_back(matrix[row][col]);
            switch (direction)
            {
            case 0: //  right
                if (col >= rb)
                {
                    direction = 1;
                    row = row + 1;
                    ub++;
                }
                else
                    col = col + 1;
                break;
            case 1: // down
                if (row >= db)
                {
                    direction = 2;
                    col = col - 1;
                    rb--;
                }
                else
                    row = row + 1;
                break;
            case 2: // left
                if (col <= lb)
                {
                    direction = 3;
                    row = row - 1;
                    db--;
                }
                else
                    col = col - 1;
                break;
            default: // up
                if (row <= ub)
                {
                    direction = 0;
                    col = col + 1;
                    lb++;
                }
                else
                    row = row - 1;
            }
        }
        return res;
    }
};