#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    set<vector<int>> s;

    int res1[2] = {0, 1};
    int res2[2] = {0, 1};

    s.insert(res1);
    s.insert(res2);

    for (auto it : s)
    {
        cout << it.size() << endl;
    }
}