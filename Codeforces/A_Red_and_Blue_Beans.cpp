#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int r, b, d;
        cin >> r >> b >> d;
        long long int smaller = min(r, b);
        long long int bigger = max(r, b);
        if (bigger <= ((smaller * (d)) + smaller))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}