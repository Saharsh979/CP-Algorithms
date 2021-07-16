// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    void solve(int row, int col, int n, vector<vector<int>> &m, string s, vector<string> &res, vector<vector<int>> &visited)
    {
        if (row == n - 1 && col == n - 1)
        {
            res.push_back(s);
            return;
        }

        if (row + 1 < n && visited[row + 1][col] == 0 && m[row + 1][col] == 1)
        {
            visited[row + 1][col] = 1;
            solve(row + 1, col, n, m, s + 'D', res, visited);
            visited[row + 1][col] = 0;
        }
        if (col - 1 >= 0 && visited[row][col - 1] == 0 && m[row][col - 1] == 1)
        {
            visited[row][col - 1] = 1;
            solve(row, col - 1, n, m, s + 'L', res, visited);
            visited[row][col - 1] = 0;
        }
        if (col + 1 < n && visited[row][col + 1] == 0 && m[row][col + 1] == 1)
        {
            visited[row][col + 1] = 1;
            solve(row, col + 1, n, m, s + 'R', res, visited);
            visited[row][col + 1] = 0;
        }
        if (row - 1 < n && visited[row - 1][col] == 0 && m[row - 1][col] == 1)
        {
            visited[row - 1][col] = 1;
            solve(row - 1, col, n, m, s + 'U', res, visited);
            visited[row - 1][col] = 0;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> res;
        string s = "";
        vector<vector<int>> visited(n, vector<int>(n, 0));
        if (m[0][0] == 1)
        {
            solve(0, 0, n, m, s, res, visited);
        }
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move,
           vector<vector<int>> &vis, int di[], int dj[])
{
    if (i == n - 1 && j == n - 1)
    {
        ans.push_back(move);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];
        if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !vis[nexti][nextj] && a[nexti][nextj] == 1)
        {
            vis[i][j] = 1;
            solve(nexti, nextj, a, n, ans, move + dir[ind], vis, di, dj);
            vis[i][j] = 0;
        }
    }
    // downward
    // if(i+1<n && !vis[i+1][j] && a[i+1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i+1, j, a, n, ans, move + 'D', vis);
    //     vis[i][j] = 0;
    // }

    // // left
    // if(j-1>=0 && !vis[i][j-1] && a[i][j-1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j-1, a, n, ans, move + 'L', vis);
    //     vis[i][j] = 0;
    // }

    // // right
    // if(j+1<n && !vis[i][j+1] && a[i][j+1] == 1) {
    //     vis[i][j] = 1;
    //     solve(i, j+1, a, n, ans, move + 'R', vis);
    //     vis[i][j] = 0;
    // }

    // // upward
    // if(i-1>=0 && !vis[i-1][j] && a[i-1][j] == 1) {
    //     vis[i][j] = 1;
    //     solve(i-1, j, a, n, ans, move + 'U', vis);
    //     vis[i][j] = 0;
    // }
}

public:
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int di[] = {+1, 0, 0, -1};
    int dj[] = {0, -1, 1, 0};
    if (m[0][0] == 1)
        solve(0, 0, m, n, ans, "", vis, di, dj);
    return ans;
}