#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int maxe = a[0];
        if (n <= 2)
        {
            cout << 0 << endl;
            continue;
        }
        vector<int> d;
        map<int, int> mp;
        for (int i = 1; i < n; i++)
        {
            int diff = a[i] - a[i - 1];
            mp[diff]++;
            if (mp[diff] == 1)
                d.push_back(a[i] - a[i - 1]);

            maxe = max(a[i], maxe);
        }
        if (d.size() == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (d.size() > 2)
        {
            cout << -1 << endl;
            continue;
        }
        if (((d[0] == 0 || d[1] == 0) && d[0] != d[1]) || abs(d[0]) + abs(d[1]) < maxe)
        {
            cout << -1 << endl;
            continue;
        }
        cout << abs(d[0]) + abs(d[1]) << " ";
        if (d[0] > 0)
            cout << d[0];
        else
            cout << d[1];
        cout << endl;
    }
    return 0;
}