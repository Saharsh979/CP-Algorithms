#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    vector<int> numbers;
    vector<char> symbols;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '+')
        {
            symbols.push_back(s[i]);
        }
        else
        {
            int val = s[i] - '0';
            numbers.push_back(val);
        }
    }
    sort(numbers.begin(), numbers.end());

    string res;
    for (int i = 0; i < numbers.size() - 1; i++)
    {
        cout << numbers[i];
        cout << '+';
    }
    cout << numbers[numbers.size() - 1];
}