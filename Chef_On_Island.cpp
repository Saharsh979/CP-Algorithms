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
        int x1, y1, d;
        cin >> x1 >> y1 >> d;
        x1 = x1 * d;
        y1 = y1 * d;
        if (x1 <= x && y1 <= y)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}