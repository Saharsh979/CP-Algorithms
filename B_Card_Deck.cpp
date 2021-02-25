#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<long long int> result;
        long long int counter = 0;
        long long int pos = 0;
        long long int val = n;
        bool flag = false;
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] != val)
            {
                if (i == n - 1)
                {
                    flag = true;
                }
                result.push_back(arr[i]);
            }
            else
            {
                result.push_back(arr[i]);
                val--;
                reverse(result.begin() + pos, result.end());
                pos = result.size();
            }
        }
        if (flag)
        {
            reverse(result.begin() + pos, result.end());
        }

        for (auto it : result)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}