#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int c1 = 0, c0 = 0, c2 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] % 3 == 0)
            {
                c0++;
            }
            else if (arr[i] % 3 == 1)
            {
                c1++;
            }
            else
            {
                c2++;
            }
        }

        if (c0 == c1 && c1 == c2)
        {
            cout << 0 << endl;
            continue;
        }
        else
        {
            if (c0 == c2 && c0 != c1)
            {
                int ans = 0;
                int a = abs(c1 - c0);
                ans += a / 2;
                int b = abs(c2 - c1);
                ans += b;
                cout << ans << endl;
                continue;
            }
            else if (c0 == c1 && c0 != c2)
            {
            }
        }
    }
}