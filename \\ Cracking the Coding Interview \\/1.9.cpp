#include <bits/stdc++.h>
using namespace std;
bool isRotation(string s1, string s2)
{
    string temp = s2 + s2;
    return (temp.find(s1) != string::npos);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    if (isRotation(s1, s2))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}