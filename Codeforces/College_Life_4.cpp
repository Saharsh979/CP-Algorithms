#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int T;
    cin >> T;
    while (T--)
    {
        long long int n, a, b, c, e, h, i, j;
        set<long long int> values;
        cin >> n >> e >> h >> a >> b >> c;

        long long int flag = 0;

        long long int x = a - c;
        long long int y = b - c;

        long long int ans = INT_MAX;

        for (i = 0; i <= n; i++)
        {
            for (j = 0; j <= n; j++)
            {
                long long int mincost = x * i + y * j + c * n;

                if (((i - j + n) <= e) && ((2 * j - i + n) <= h))
                {
                    if ((n - i - j) >= 0)
                    {
                        flag = 1;
                        values.insert(mincost);
                    }
                }
            }
        }
        if (flag == 1)
        {
            long long int ans = INT_MAX;
            for (auto it : values)
            {
                ans = min(ans, it);
            }
            cout << ans << "\n";
        }
        else
        {
            cout << "-1"
                 << "\n";
        }
    }
    return 0;
}