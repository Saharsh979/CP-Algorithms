#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, k;
    cin >> n >> k;
    long long int maxval = 0;
    long long int ways = 1;

    long long int arr[n];
    for (long long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] > n - k)
        {
            maxval += arr[i];
            arr[i] = 0;
        }
    }

    bool flag = false;
    long long int pos = 0;

    for (long long int i = 0; i < n; i++)
    {
        if (arr[i] == 0 && flag == true)
        {
            ways = (ways % 998244353 * (i - pos) % 998244353) % 998244353;
            pos = i;
        }
        if (arr[i] == 0)
        {
            flag = true;
            pos = i;
        }
    }
    cout << maxval << " " << ways << endl;
}