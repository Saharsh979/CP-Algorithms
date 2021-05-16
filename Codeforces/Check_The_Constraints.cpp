#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = false;
        int answer = INT_MAX;
        int count = 0;
        sort(arr, arr + n);
        if (arr[n - 1] == 0)
        {
            cout << 0 << " " << 0 << endl;
        }
        else if (arr[n - 1] == 1)
        {
            cout << 1 << " " << 1 << endl;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] > 1)
                {
                    count++;
                    answer = min(answer, arr[i]);
                }
            }
            cout << count << " " << answer << endl;
        }
    }
}