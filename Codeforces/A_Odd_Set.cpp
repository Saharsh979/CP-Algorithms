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
        int size = 2 * n;
        int x = 0;
        for (int i = 0; i < size; i++)
        {
            int val;
            cin >> val;
            if (val % 2 == 1)
            {
                x++;
            }
        }
        if (x == n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
