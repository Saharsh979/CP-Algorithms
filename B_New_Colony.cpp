#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> pos;
        bool flag = false;
        int ans = 0;
        while (k-- && flag != true)
        {
            bool f1 = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    f1 = true;
                    ans = i + 1;
                    arr[i]++;
                }
                if (f1 == true)
                {
                    break;
                }
            }
            if (f1 == false)
            {
                flag = true;
            }
        }
        if (flag == true)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }
}