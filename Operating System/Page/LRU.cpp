#include <bits/stdc++.h>
using namespace std;
int pageFaults(int pages[], int n, int capacity)
{
    unordered_set<int> s;
    unordered_map<int, int> indexes;
    int page_faults = 0;
    for (int i = 0; i < n; i++)
    {
        // Check if the set can hold more pages
        if (s.size() < capacity)
        {
            // Insert it into set if not present
            // already which represents page fault
            if (s.find(pages[i]) == s.end())
            {
                s.insert(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
        // If the set is full then need to perform lru
        else
        {
            // Check if current page is not already
            // present in the set
            if (s.find(pages[i]) == s.end())
            {
                // Find the least recently used pages
                // that is present in the set
                int lru = INT_MAX, val;
                for (auto it = s.begin(); it != s.end(); it++)
                {
                    if (indexes[*it] < lru)
                    {
                        lru = indexes[*it];
                        val = *it;
                    }
                }
                // Remove the indexes page
                s.erase(val);
                // insert the current page
                s.insert(pages[i]);
                // Increment page faults
                page_faults++;
            }
            // Update the current page index
            indexes[pages[i]] = i;
        }
    }
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
    cout << "No of Page Faults is"
         << " " << pageFaults(pages, n, capacity);
    return 0;
}
