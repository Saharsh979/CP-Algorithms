// C++ Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

int isSafe(int **M, int row, int col, bool **visited, int sizerow, int sizecol)
{
    return (row >= 0) && (row < sizerow) && (col >= 0) && (col < sizecol) && (M[row][col] && !visited[row][col]);
}

int DFS(int **M, int row, int col, bool **visited, int count, int sizerow, int sizecol)
{
    static int rowNbr[] = {-1, 0, 0, 1};
    static int colNbr[] = {0, -1, 1, 0};
    visited[row][col] = true;

    for (int k = 0; k < 4; ++k)
    {
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited, sizerow, sizecol))
        {
            DFS(M, row + rowNbr[k], col + colNbr[k], visited, count + 1, sizerow, sizecol);
        }
    }
    return count;
}

vector<int> countIslands(int **M, int row, int col)
{
    bool visited[row][col];
    memset(visited, 0, sizeof(visited));
    int count = 0;
    vector<int> result;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (M[i][j] && !visited[i][j])
            {
                int size_curr = DFS(M, i, j, visited, 0, row, col);
                result.push_back(size_curr);
                ++count;
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int M[n][m];
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
            {
                char c = s[j];

                M[i][j] = ((c == '1') ? 1 : 0);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << M[i][j] << " ";
            }
            cout << endl;
        }
        vector<int> res = countIslands(M, n, m);
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}