#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        string s;
        cin >> s;
        int up = 0;
        int down = 0;
        int right = 0;
        int left = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'R')
            {
                right++;
            }
            if (s[i] == 'U')
            {
                up++;
            }
            if (s[i] == 'L')
            {
                left++;
            }
            if (s[i] == 'D')
            {
                down++;
            }
        }
        bool flag1 = false;
        bool flag2 = false;
        if (x >= 0)
        {
            if (right >= x)
            {
                flag1 = true;
            }
        }
        else
        {
            if (left >= abs(x))
            {
                flag1 = true;
            }
        }

        if (y >= 0)
        {
            if (up >= y)
            {
                flag2 = true;
            }
        }
        else
        {
            if (down >= abs(y))
            {
                flag2 = true;
            }
        }
        if (flag1 && flag2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}