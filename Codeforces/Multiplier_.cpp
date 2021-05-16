#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int answer = 1;
    for (int i = 3; i <= 12; i++)
    {
        answer = answer * i;
    }
    cout << answer << endl;
}