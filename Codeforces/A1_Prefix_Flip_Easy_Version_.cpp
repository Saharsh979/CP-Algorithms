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
        string a, b;
        cin >> a >> b;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                res.push_back(i + 1);
                res.push_back(1);
                res.push_back(i + 1);
            }
        }
        cout << res.size() << " ";
        for (auto it : res)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}