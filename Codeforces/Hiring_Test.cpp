#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int x, y;
        cin >> x >> y;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            int xcount = 0;
            int ycount = 0;
            for (int j = 0; j < s.length(); j++)
            {
                if (s[j] == 'P')
                {
                    ycount++;
                }
                else if (s[j] == 'F')
                {
                    xcount++;
                }
            }
            if ((xcount >= x) || (xcount >= x - 1 && ycount >= y))
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << endl;
    }
}