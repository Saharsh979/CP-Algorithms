#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    queue<int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        if (s.size() < capacity)
        {
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
                // cout << "MISS" << endl;
                indexes.push(pages[i]);
            }
            else
            {
                // cout << "HIT" << endl;
            }
        }
        else
        {
            if (s.find(pages[i]) == s.end())
            {
                int val = indexes.front();
                // cout << "MISS" << endl;
                indexes.pop();
                s.erase(val);
                s.insert(pages[i]);
                indexes.push(pages[i]);
                page_faults++;
            }
            else
            {
                //  cout << "HIT" << endl;
            }
        }
    }
    cout << "No of Page Faults ";
    return page_faults;
}

int main()
{
    int n;
    cin >> n;
    cout << "No of Frames"
         << " " << n << endl;
    int capacity;
    cin >> capacity;
    cout << "Capacity"
         << " " << capacity << endl;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    cout << pageFaults(pages, n, capacity);
    return 0;
}