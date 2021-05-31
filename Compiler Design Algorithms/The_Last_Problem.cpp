#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x1, y1;
        cin >> x1 >> y1;

        int dist_y = y1 - 1;
        int dist_x = x1 - 1;

        int y = 1;
        int x = y1 + 1;

        int start = 1;
        while (dist_y--)
        {
            start += y;
            y++;
        }

        while (dist_x--)
        {
            start += x;
            x++;
        }
        int ans = start;
        int x2, y2;
        cin >> x2 >> y2;

        int a1 = y2 - y1;
        int a2 = x2 - x1;

        int val1 = x2 + y1 - 1;
        int val2 = x1 + y1;
        while (a2--)
        {

            start += val2;
            ans += start;
            val2++;
            //cout << start << endl;
        }
        while (a1--)
        {

            start += val1;
            ans += start;
            val1++;
            //cout << start << endl;
        }
        cout << ans << endl;
        //cout << start << endl;
    }
}