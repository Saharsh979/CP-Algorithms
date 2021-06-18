#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, a1, b1;
        cin >> a >> b >> a1 >> b1;
        int ans1 = 0;
        int ans2 = 0;
        int finalans = 0;
        ans1 = a1 / a;
        if (a1 % a != 0)
        {
            ans1++;
        }
        ans2 = b1 / b;
        if (b1 % b != 0)
        {
            ans2++;
        }
        finalans = ans1 + ans2;
        cout << finalans << endl;
    }
}