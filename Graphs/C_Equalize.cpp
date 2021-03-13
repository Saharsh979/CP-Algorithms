#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int i = 0;
    int j = 0;

    int count = 0;

    while (i < n)
    {
        if (a[i] == b[i])
        {
            i++;
        }
        else
        {
            if (a[i + 1] != a[i] && b[i + 1] != b[i])
            {
                swap(a[i], a[i + 1]);
                count++;
                i++;
            }
            else
            {
                count++;
                i++;
            }
        }
    }
    cout << count << endl;
}
