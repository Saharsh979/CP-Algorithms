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
        long long int arr[n];
        long long int sum = 0;
        bool flag = true;
        for (long long int i = 0; i < n; i++)
        {
            cin >> arr[i];
            sum += arr[i];
            if (sum < ((i * (i + 1)) / 2))
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}