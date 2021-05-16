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
    int count = 0;
    for (int l = 0; l < n; l++)
    {
        int val = 0;
        vector<bool> seen(1001);
        for (int r = l; r < n; r++)
        {
            val += arr[r];
            seen[arr[r]] = true;
            int size = r - l + 1;
            if (val % size == 0)
            {
                int avg = val / size;
                if (seen[avg])
                {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}