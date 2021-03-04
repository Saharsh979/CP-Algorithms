#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;

        if (n % 2 == 0)
        {
            cout << n / 2 << " " << n / 2 << endl;
            continue;
        }
        bool flag = false;
        for (long long int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                cout << n / i << " " << n - (n / i) << endl;
                flag = true;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            cout << 1 << " " << n - 1 << endl;
        }
    }
}