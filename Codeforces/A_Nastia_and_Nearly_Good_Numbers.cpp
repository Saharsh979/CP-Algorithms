#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, m;
        cin >> n >> m;
        if (n * m < 2 * n)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            long long int x, y, z;
            z = n * m * 2;
            x = n;
            y = z - x;
            cout << x << " " << y << " " << z << endl;
        }
    }
}