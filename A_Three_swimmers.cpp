#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long p, a, b, c;
        cin >> p >> a >> b >> c;

        long long A = ((p + a - 1) / a) * a;
        long long B = ((p + b - 1) / b) * b;
        long long C = ((p + c - 1) / c) * c;

        long long ans = min(min(abs(p - A), abs(p - B)), abs(p - C));
        cout << ans << "\n";
    }
    return 0;
}