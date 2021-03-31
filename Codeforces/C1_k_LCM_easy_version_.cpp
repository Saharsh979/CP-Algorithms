#include <bits/stdc++.h>
#define ll long long int;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (n % 2 != 0)
        {
            cout << "1"
                 << " " << (n - 1) / 2 << " " << (n - 1) / 2;
        }
        else if (n % 2 == 0)
        {
            if ((n / 2) % 2 != 0)
            {
                cout << "2"
                     << " " << (n - 2) / 2 << " " << (n - 2) / 2;
            }
            else
            {
                cout << n / 2 << " " << n / 4 << " " << n / 4;
            }
        }
        cout << endl;
    }
}
