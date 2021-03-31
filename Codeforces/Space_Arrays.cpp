#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int T;
    cin >> T;
    while (T--)
    {
        long long int i, j, count = 0, N, flag = 0;
        cin >> N;
        long long int a[N + 1];
        for (i = 1; i <= N; i++)
        {
            cin >> a[i];
        }
        sort(a + 1, a + N + 1);
        for (j = 1; j <= N; j++)
        {
            if (a[j] > j)
            {
                flag = 1;
                break;
            }
            else
            {
                count = count + (j - a[j]);
            }
        }
        if (flag == 1)
        {
            cout << "Second" << endl;
        }
        else
        {
            if (count % 2 == 0)
            {
                cout << "Second" << endl;
            }
            else
            {
                cout << "First" << endl;
            }
        }
    }
    return 0;
}