#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define ll long long int

const int MAX_N = 205000;
const int MOD = 1e9 + 7;
const int N = 1e6 + 1;

ll a[N];

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        cout << n << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            cout << a[i];
        }
        ll ans = (a[0] + a[1]) * n;
        ll even_sum[N];
        ll odd_sum[N];
        even_sum[0] = a[0];
        odd_sum[1] = a[1];
        for (int i = 2; i < n - 2; i += 2)
        {
            even_sum[i] = even_sum[i - 2] + a[i];
        }
        for (int i = 3; i < n - 2; i += 2)
        {
            odd_sum[i] = odd_sum[i - 2] + a[i];
        }
        ll even = a[0];
        ll odd = a[1];
        ll even_ans = a[0] * n;
        ll odd_ans = a[1] * n;
        for (int i = 2; i < n; i++)
        {
            if (i % 2 == 0)
            {
                if (a[i] < even)
                {
                    even = a[i];
                    even_ans = even_sum[i - 2] * 1 + (n - (i / 2) - 1) * even;
                }
                else
                {
                    even_ans = (even_sum[i] - even) * 1 + (n - (i / 2) - 1) * even;
                }
                ans = min(ans, even_ans + odd_ans);
            }
            else
            {
                if (a[i] < odd)
                {
                    odd = a[i];
                    odd_ans = odd_sum[i - 2] * 1 + (n - ((i - 1) / 2) - 1) * odd;
                }
                else
                {
                    odd_ans = (odd_sum[i] - odd) * 1 + (n - ((i - 1) / 2) - 1) * odd;
                }
                ans = min(ans, even_ans + odd_ans);
            }
        }
        cout << ans << endl;
    }
}