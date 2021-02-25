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
        int count = 0;
        int curr = -1;
        int prev = -1;
        int next = -1;

        int i = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int x = min(arr[i], arr[i + 1]);
            int y = max(arr[i], arr[i + 1]);

            while ((2 * x) < y)
            {
                x = x * 2;
                count++;
            }
        }

        cout << count << endl;
    }
}