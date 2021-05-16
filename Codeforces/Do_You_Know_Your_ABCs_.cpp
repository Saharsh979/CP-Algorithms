#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[7];
    for (int i = 0; i < 7; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + 7);
    for (int i = 0; i < 2; i++)
    {
        cout << arr[i] << " ";
    }
    int val = arr[6] - (arr[0] + arr[1]);
    cout << val << endl;
}