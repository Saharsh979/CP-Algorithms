#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a % 2 == 0)
    {
        int val1 = a / 2;
        cout << val1 * b << endl;
    }
    else if (b % 2 == 0)
    {
        int val1 = b / 2;
        cout << val1 * a << endl;
    }
    else
    {
        int val1 = a / 2;
        int val2 = val1 * b;
        val2 += b / 2;
        cout << val2 << endl;
    }
}