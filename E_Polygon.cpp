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
        int arr[n][n];
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < n; j++)
            {
                arr[i][j] = (s[j] == '0') ? 0 : 1;
            }
        }

        bool flag = true;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (arr[i][j] == 1)
                {
                    if (arr[i + 1][j] == 0 && arr[i][j + 1] == 0)
                    {
                        flag = false;
                        break;
                    }
                }
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