#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> res;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            res.push_back(i + 1);
        }
    }

    if (res.size() == 0)
    {
        cout << 0 << endl;
    }
    else if ((res.size() == 1))
    {
        cout << 1 << endl;
    }
    else
    {

        long long int ans = 1;
        for (int i = 1; i < res.size(); i++)
        {
            ans = ans * (res[i] - res[i - 1]);
        }
        cout << ans << endl;
    }
}