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
    bool flagdig = false;
    int dip = -1;
    bool flagup = false;
    int up = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            if (flagdig == true)
            {
                continue;
            }
            else
            {
                dip = i + 1;
                flagdig = true;
            }
        }
        else
        {
            if (flagdig == false)
            {
                continue;
            }
            else
            {
                flagup = true;
                up = i + 1;
                break;
            }
        }
    }

    if (up == -1 && dip != -1)
    {
        up = n;
    }

    reverse(arr + dip - 1, arr + up);

    bool ans = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            ans = false;
            break;
        }
    }

    if (up == -1 && dip == -1)
    {
        cout << "yes" << endl;
        cout << '1' << " " << '1' << endl;
    }
    else if (ans)
    {
        cout << "yes" << endl;
        cout << dip << " " << up << endl;
    }
    else
    {
        cout << "no" << endl;
    }
}

//https://codeforces.com/problemset/problem/451/B