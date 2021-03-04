#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        long long int u1 = u, r1 = r, d1 = d, l1 = l;
        if (u == n)
        {
            r1--;
            l1--;
        }
        if (r == n)
        {
            u1--;
            d1--;
        }
        if (d == n)
        {
            r1--;
            l1--;
        }
        if (l == n)
        {
            u1--;
            d1--;
        }
        if (u == n - 1)
        {
            if (r1 > l1)
                r1--;
            else
                l1--;
        }
        if (r == n - 1)
        {
            if (u1 > d1)
                u1--;
            else
                d1--;
        }
        if (d == n - 1)
        {
            if (r1 > l1)
                r1--;
            else
                l1--;
        }
        if (l == n - 1)
        {
            if (u1 > d1)
            {
                u1--;
            }
            else
            {
                d1--;
            }
        }
        if (u1 >= 0 && r1 >= 0 && d1 >= 0 && l1 >= 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}