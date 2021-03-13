#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {

        int i, j, k, C, maxval = 0, d = 0;
        cin >> C;
        while (pow(2, d) < C)
        {
            d++;
        }
        vector<int> v;
        int number = pow(2, d);

        for (i = 0; i <= number; i++)
        {
            for (j = i + 1; j <= number; j++)
            {
                if ((i ^ j) == C)
                {
                    maxval = max(maxval, i * j);
                }
            }
        }

        cout << maxval << "\n";
    }
    return 0;
}
