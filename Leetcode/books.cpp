#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first < b.first)
    {
        return true;
    }
    else
    {
    }
    return (a.second < b.second);
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int limit[n];
    for (int i = 0; i < n; i++)
    {
        cin >> limit[n];
    }
    vector<pair<int, int>> books;

    for (int i = 0; i < n; i++)
    {
        books.push_back(make_pair(arr[i], limit[i]));
    }

    sort(books.begin(), books.end(), compare);
}