#include <bits/stdc++.h>
using namespace std;

void countAllPossible(char set[], string prefix, int n, bool flagy, bool flagz, int count)
{
    cout << prefix << endl;
    if (n == 0)
    {
        count++;
    }
    int i = 0;
    while (i < 3)
    {
        string newPrefix;
        if (i == 0)
        {
            newPrefix = prefix + set[i];
            i++;
        }
        else
        {
            if (i == 1)
            {
                if (flagy == true)
                {
                    i++;
                    continue;
                }
                else
                {
                    newPrefix = prefix + set[i];
                    flagy = true;
                    i++;
                    countAllPossible(set, newPrefix, n - 1, flagy, flagz, count);
                }
            }
            else
            {
                if (i == 2)
                {
                    if (prefix[prefix.length() - 1] != 'z')
                    {
                        i = 0;
                        newPrefix = prefix + set[i];
                        countAllPossible(set, newPrefix, n - 1, flagy, flagz, count);
                    }
                    else
                    {
                        if (!flagz)
                        {
                            i = 0;
                            newPrefix = prefix + set[i];
                            flagz = true;
                            countAllPossible(set, newPrefix, n - 1, flagy, flagz, count);
                        }
                        else
                        {
                            i = 0;
                            flagz = false;
                            continue;
                        }
                    }
                }
            }
        }
    }
}
int echoStringCount(int n)
{
    char set[] = {'x', 'y', 'z'};
    bool flagy = false;
    bool flagz = false;
    int count = 0;
    countAllPossible(set, "", n, flagy, flagz, count);
    return count;
}

int main()
{
    int n;
    cin >> n;
    cout << echoStringCount(n) << endl;
}