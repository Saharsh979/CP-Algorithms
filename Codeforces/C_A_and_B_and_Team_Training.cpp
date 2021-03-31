#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int smaller = min(n, m);
    int bigger = max(n, m);

    int answer = 0;
    answer = (n + m) / 3;
    answer = min(answer, smaller);
    /*
    int curr = bigger / 2;
    if (smaller == curr)
    {
        cout << curr << endl;
        return 0;
    }
    else if (smaller < curr)
    {
        cout << smaller << endl;
        return 0;
    }
    else
    {
        answer += curr;
        smaller = smaller - curr;
        answer += smaller / 3;
        cout << answer << endl;
        return 0;
    }
    */
    cout << answer << endl;
}