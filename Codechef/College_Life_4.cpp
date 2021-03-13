#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int a, b, c, t, e, n, h;
        cin >> n >> e >> h >> a >> b >> c;

        long long int possibleitems = 0;
        if (e == h)
        {
            possibleitems = e;
        }
        if (e > h)
        {
            possibleitems = h + (e - h) / 2;
        }
        if (h > e)
        {
            possibleitems = e + (h - e) / 2;
        }
        if (possibleitems < n)
        {
            cout << -1 << "\n";
            continue;
        }
        else
        {
            set<long long int> setvalues;
            if ((e / 2) >= n)
            {
                long long int value = a * n;
                setvalues.insert(value);
            }
            if ((h / 3) >= n)
            {
                long long int value = b * n;
                setvalues.insert(value);
            }
            if (min(e, h) >= n)
            {
                long long int value = c * n;
                setvalues.insert(value);
            }
            if (((e / 2) >= 1 && (h / 3) >= 1 && ((e / 2) + (h / 3)) >= n))
            {
                long long int value;
                if (a < b)
                {
                    value = min(n - 1, (e / 2)) * a + (n - min(n - 1, (e / 2))) * b;
                }
                else
                {
                    value = min(n - 1, (h / 3)) * b + (n - min(n - 1, (h / 3))) * a;
                }
                setvalues.insert(value);
            }

            if (((e - n) >= 1 && h >= 1 && (e + h) >= 2 * n))
            {
                long long int value;
                if (a < c)
                {
                    value = min(n - 1, (e / 2)) * a + (n - min(n - 1, (e / 2))) * c;
                }
                else
                {
                    value = min(n - 1, min(h, e)) * c + (n - min(n - 1, min(h, e))) * a;
                }
                setvalues.insert(value);
            }

            if (((h - n) >= 2 && e >= 1 && (e + h) >= 2 * n))
            {
                long long int value;
                if (b < c)
                {
                    value = min(n - 1, (h / 3)) * b + (n - min(n - 1, (h / 3))) * c;
                }
                else
                {
                    value = min(n - 1, min(h, e)) * c + (n - min(n - 1, min(h, e))) * b;
                }
                setvalues.insert(value);
            }
            if ((((h + e) / 2) >= (n - 2) && e >= n && h >= n + 1))
            {
                long long int value;
                if (a == min(a, min(b, c)))
                {
                    long long int x1 = min(n - 2, e / 2) * a;
                    long long int n1 = n - min(n - 2, e / 2);
                    if (b < c)
                    {
                        value = min(n1 - 1, (h / 3)) * b + (n1 - min(n1 - 1, (e / 3))) * c + x1;
                    }
                    else
                    {
                        value = min(n1 - 1, min(h, e)) * c + (n1 - min(n1 - 1, min(h, e))) * b + x1;
                    }
                }
                else if (b == min(a, min(b, c)))
                {
                    long long int x1 = min(n - 2, h / 3) * b;
                    long long int n1 = n - min(n - 2, h / 3);
                    if (a < c)
                    {
                        value = min(n1 - 1, (e / 2)) * a + (n1 - min(n1 - 1, (e / 2))) * c + x1;
                    }
                    else
                    {
                        value = min(n1 - 1, min(h, e)) * c + (n1 - min(n1 - 1, min(h, e))) * a + x1;
                    }
                }
                else
                {
                    long long int x1 = min(n - 2, min(h, e)) * c;
                    long long int n1 = n - min(n - 2, min(h, e));
                    long long int e1 = e - min(n - 2, min(h, e));
                    long long int h1 = h - min(n - 2, min(h, e));
                    if (a < b)
                    {
                        value = min(n1 - 1, (e1 / 2)) * a + (n1 - min(n1 - 1, (e1 / 2))) * b + x1;
                    }
                    else
                    {
                        value = min(n1 - 1, (h1 / 3)) * b + (n1 - min(n1 - 1, (h1 / 3))) * a + x1;
                    }
                }
                setvalues.insert(value);
            }

            if (setvalues.size() == 0)
            {
                cout << -1 << endl;
            }
            else
            {
                long long int answer = INT_MAX;
                for (auto it : setvalues)
                {
                    answer = min(answer, it);
                }
                cout << answer << endl;
            }
        }
    }
    return 0;
}