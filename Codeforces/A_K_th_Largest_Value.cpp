#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] == 1)
        {
            count++;
        }
    }
    while (q--)
    {
        int type, val;
        cin >> type >> val;

        if (type == 1)
        {
            if (arr[val - 1] == 1)
            {
                count--;
                arr[val - 1] = 0;
            }
            else
            {
                count++;
                arr[val - 1] = 1;
            }
        }
        else
        {
            if (val <= count)
            {
                cout << "1" << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}