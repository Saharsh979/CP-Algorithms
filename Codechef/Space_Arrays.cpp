#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int i, j, count = 0, N, flag = 0;
        cin >> N;
        int a[N + 1];
        for (i = 1; i <= N; i++)
        {
            cin >> a[i];
        }
        sort(a, a + N + 1);
        for (j = 1; j <= N; j++)
        {
            if (a[j] > i)
            {
                cout << "Second" << endl;
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
            continue;
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