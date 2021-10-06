#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int count = 0;
    int i = 0;
    int j = 0;

    while (i < n)
    {
        char prev = s[i];
        int j = i + 1;
        while (j < n)
        {
            if (s[j] == prev)
            {
                count++;
                j++;
            }
            else
            {
                break;
            }
        }
        i = j;
    }
    cout << count << endl;
}