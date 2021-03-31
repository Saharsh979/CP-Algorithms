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
        sort(arr, arr + n);

        vector<int> res;
        res.push_back(arr[0]);
        vector<int> badele;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] != arr[i - 1])
            {
                res.push_back(arr[i]);
            }
            else
            {
                badele.push_back(arr[i]);
            }
        }
        for (int i = 0; i < badele.size(); i++)
        {
            res.push_back(badele[i]);
        }

        for (int i = 0; i < n; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        }
}