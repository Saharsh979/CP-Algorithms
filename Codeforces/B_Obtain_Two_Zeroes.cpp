#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int a, b;
        cin >> a >> b;

        int small = min(a, b);
        int big = max(a, b);
        if (((small + big) % 3 == 0) && (small * 2 >= big))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}