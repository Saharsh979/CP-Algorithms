#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        if (s.size() == k)
        {
            int count = 0;
            for (int i = 0; i < k; i++)
            {
                if (s[i] == '0')
                {
                    count++;
                }
            }
            if (count == k)
            {
                cout << 1 << endl;
                continue;
            }
            else
            {
                cout << 0 << endl;
                continue;
            }
        }
        int val = (2 * k) + 1;
        int prefix[n];

        int ans = 0;
        if (s[0] == '0')
        {
            int count_0 = 0;
            for (int i = 0; i < min(n, k + 1); i++)
            {
                if (s[i] == '0')
                {
                    count_0++;
                }
            }
            if (count_0 == k + 1)
            {
                s[0] = '1';
                ans++;
            }
        }
        if (s[n - 1] == '0')
        {
            int count_n = 0;
            for (int i = n - 1; i >= max(0, n - k - 1); i--)
            {
                if (s[i] == '0')
                {
                    count_n++;
                }
            }
            if (count_n == k + 1)
            {
                s[n - 1] = '1';
                ans++;
            }
        }
        if (s[0] == '0')
        {
            prefix[0] = 1;
        }
        else
        {
            prefix[0] = 0;
        }
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                prefix[i] = (prefix[i - 1] == 0) ? 1 : prefix[i - 1] + 1;
            }
            else
            {
                prefix[i] = 0;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n; i++)
        {
            cout << prefix[i] << " ";
        }
        cout << endl;

        int i = 1;
        int j = val;

        while (j < n)
        {
            int x1 = prefix[i];
            int x2 = prefix[j];

            int exdi = x2 - x1;

            //cout << exdi << endl;
            if (exdi == val)
            {
                cout << i << " " << prefix[i] << " " << j << " " << prefix[j] << endl;
                ans++;
            }
            i = i + val - 1;
            j = j + val - 1;
        }
        cout << ans << endl;
    }
}