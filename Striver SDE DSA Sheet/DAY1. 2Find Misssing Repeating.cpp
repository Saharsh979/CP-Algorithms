// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            mp[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]]++;
        }
        int missing = -1;
        int repeating = -1;

        for (auto it : mp)
        {
            if (it.second > 1)
            {
                repeating = it.first;
            }
            if (it.second == 0)
            {
                missing = it.first;
            }
        }
        arr[0] = repeating;
        arr[1] = missing;

        return arr;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends