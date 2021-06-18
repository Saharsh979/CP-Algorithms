#include <bits/stdc++.h>
using namespace std;
//=n/2[First Term+Last Term]
//n=Last number−First number+1
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int days, interval, p, q;
        cin >> days >> interval >> p >> q;
        long long int ans = 0;
        long long int counter = 0;
        if (interval == 1)
        {
            ans = ans + ((days / 2) * (2 * p) + (days - 1) * q);
            cout << ans << endl;
        }
        else
        {
            while (days)
            {
                //cout << days << " " << p << endl;
                if (days >= interval)
                {

                    ans = ans + (interval * p);
                    days = days - interval;
                    p = p + q;
                }
                else
                {
                    ans = ans + (days * p);
                    p = p + q;
                    break;
                }
                // cout << ans << endl;
            }
            cout << ans << endl;
        }
    }
}