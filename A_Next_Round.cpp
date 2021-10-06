#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i < k && arr[i] > 0)
        {
            count2++;
        }
    }
    int val = arr[k - 1];
    int count = 0;
    int x = k;
    while (x < n)
    {
        if (arr[x] == val && arr[x] != 0)
        {
            x++;
            count++;
        }
        else
        {
            break;
        }
    }
    if (val == 0)
    {
        cout << count2 << endl;
    }
    else
    {
        cout << count + k << endl;
    }
}