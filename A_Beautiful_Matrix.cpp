#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int row = 0;
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                row = i + 1;
                col = j + 1;
                break;
            }
        }
    }
    int midrow = 3;
    int midcol = 3;

    int ans = abs(midrow - row) + abs(midcol - col);
    cout << ans << endl;
}