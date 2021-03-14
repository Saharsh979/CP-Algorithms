#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c, t, e, n, h;
        cin >> n >> e >> h >> a >> b >> c;
        long long int ans = INT_MAX;
        set<long long int> setvalues;
        if ((e / 2) >= n)
        {
            long long int value = a * n;
            ans = min(ans, value);
            setvalues.insert(value);
        }
        if ((h / 3) >= n)
        {
            long long int value = b * n;
            ans = min(ans, value);
            setvalues.insert(value);
        }
        if (min(e, h) >= n)
        {
            long long int value = c * n;
            ans = min(ans, value);
            setvalues.insert(value);
        }
        if ((((h - n) / 2) >= 1) && ((h - n) / 2) >= n - e)
        {
            if (b < c)
            {
                long long int temp = min(n - 1, (h - n) / 2);
                long long int value = (b - c) * temp + n * c;
                ans = min(ans, (b - c) * temp + n * c);
                setvalues.insert(value);
            }
            else
            {
                long long int one = 1;
                long long int temp = max(one, n - e);
                long long int value = (b - c) * temp + n * c;
                ans = min(ans, value);
                setvalues.insert(value);
            }
        }
        if (((e - n) >= 1) && ((e - n) >= n - h))
        {
            if (a < c)
            {
                long long int temp = min(n - 1, (e - n));
                long long int value = (a - c) * temp + n * c;
                ans = min(ans, value);
                setvalues.insert(value);
            }
            else
            {
                long long int one = 1;
                long long int temp = max(one, n - h);
                long long int value = (a - c) * temp + n * c;
                ans = min(ans, value);
                setvalues.insert(value);
            }
        }
        if ((((e / 2) >= 1) && (e/2 >= (3*n - h+2)/3))
        {
            if (a < b)
            {
                long long int temp = min(n - 1, e / 2);
                long long int value = (a - b) * k + n * b;
                ans = min(ans, value);
                setvalues.insert(value);
            }
            else
            {
                long long int one = 1;
                long long int temp = max(one, (3 * n - h + 2) / 3);
                long long int value = (a - b) * k + n * b;
                ans = min(ans, value);
                setvalues.insert(value);
            }
        }
    }
}
