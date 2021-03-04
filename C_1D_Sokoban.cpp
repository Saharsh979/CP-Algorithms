#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

int solve(vector<int> val, vector<int> special)
{
    int i = val.size() - 1;
    int j = special.size() - 1;
    if (val.size() == 0 || special.size() == 0)
    {
        return 0;
    }
    if (special.size() == 1)
    {
        for (int i = 0; i < special.size(); i++)
        {
            if (val[i] <= special[0])
            {
                return 1;
            }
        }
    }
    int count = 0;
    int finalans = 0;
    while (i >= 0 && j >= 0)
    {
        if (val[i] == special[j])
        {
            i--;
            j--;
            count++;
            finalans = max(finalans, count);
        }
        else if (val[i] > special[j])
        {
            i--;
        }
        else
        {
            int pos = lower_bound(special.begin(), special.end(), special[j] - i) - special.begin();
            int diff = min(i + 1, j - pos + 1);
            finalans = max(finalans, count + diff);
            j--;
        }
    }
    return finalans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> positiveval;
        vector<int> positivespecial;
        vector<int> negativeval;
        vector<int> negativespecial;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            (x < 0) ? negativeval.push_back(-x) : positiveval.push_back(x);
        }
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            (x < 0) ? negativespecial.push_back(-x) : positivespecial.push_back(x);
        }

        sort(all(negativespecial));
        sort(all(negativeval));
        sort(all(positivespecial));
        sort(all(positiveval));

        int answer = solve(negativeval, negativespecial) + solve(positiveval, positivespecial);
        cout << answer << endl;
    }
}