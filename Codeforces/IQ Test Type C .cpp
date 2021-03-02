#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int even = 0;
    int odd = 0;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    if (even == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 1)
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
}

//https://codeforces.com/problemset/problem/25/A