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
        vector<int> arr(n);
        for (long long int i = 0; i < n; i++)
        {
            long long int x;
            cin >> x;
            arr[i] = x;
        }
        sort(arr.begin(), arr.end());
        bool flag = false;
        long long int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > i + 1)
            {
                flag = true;
                break;
            }
            else
            {
                count++;
            }
        }
        if (flag)
        {
            cout << "Second" << endl;
        }
        else
        {
            long long int no_of_turns = 0;
            for (int i = 0; i < n; i++)
            {
                no_of_turns += ((i + 1) - arr[i]);
            }
            if (no_of_turns % 2 == 1)
            {
                cout << "First" << endl;
            }
            else
            {
                cout << "Second" << endl;
            }
        }
    }
}
