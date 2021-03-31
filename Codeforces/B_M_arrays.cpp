#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n];
        map<int, int> check;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr[i] = arr[i] % m;
            check[arr[i]]++;
        }

        int ans = 0;
        if (check[0] > 0)
        {
            ans++;
        }
        for (int i = 1; i <= m / 2; i++)
        {
            if ((m % 2 == 0) && (i == m / 2) && (check[i] != 0))
            {
                ans = ans + 1;
                continue;
            }
            if (check[i] == 0 && check[m - i] == 0)
            {
                continue;
            }
            if (check[i] == check[m - i] && check[i] > 0)
            {
                ans++;
                continue;
            }
            if (check[i] == 0)
            {
                ans += check[m - i];
                continue;
            }
            if (check[m - i] == 0)
            {
                ans += check[i];
                continue;
            }
            ans++;
            int first = check[i];
            int second = check[m - i];
            int maxval = max(first, second);
            int minval = min(first, second);
            ans += (maxval - minval - 1);
        }
        cout << ans << endl;
    }
    return 0;
}