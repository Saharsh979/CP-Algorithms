#include <bits/stdc++.h>
using namespace std;

map<int, int> primeFactors(int n)
{
    map<int, int> result;
    int count = 0;
    while (n % 2 == 0)
    {
        count++;
        n = n / 2;
    }
    if (count > 0)
    {
        result[2] = count;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n = n / i;
        }
        if (count > 0)
        {
            result[i] = count;
        }
    }
    if (n > 2)
    {
        result[n] = 1;
    }
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        map<int, int> prime = primeFactors(n);
        bool flag = false;
        vector<int> result;

        for (auto it : prime)
        {
            int x = 1;
            while (it.second >= x)
            {
                int val = pow(it.first, x);
                result.push_back(val);
                it.second = it.second - x;
                x++;
            }
        }
        if (result.size() > 2)
        {
            cout << "YES" << endl;
            cout << result[0] << " " << result[1] << " " << result[2] << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}

//https://codeforces.com/problemset/problem/1294/C