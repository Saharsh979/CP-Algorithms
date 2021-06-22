#include <bits/stdc++.h>
using namespace std;

bool search(int key, vector<int> &fr)
{
    for (int i = 0; i < fr.size(); i++)
        if (fr[i] == key)
            return true;
    return false;
}
int predict(int pg[], vector<int> &fr, int pn, int index)
{
    // Store the index of pages which are going
    // to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fr.size(); i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == pn)
            return i;
    }
    return (res == -1) ? 0 : res;
}
void optimalPage(int pg[], int pn, int fn)
{
    vector<int> fr;
    // Traverse through page reference array
    // and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < pn; i++)
    {
        // Page found in a frame : HIT
        if (search(pg[i], fr))
        {
            hit++;
            continue;
        }
        // Page not found in a frame : MISS
        // If there is space available in frames.
        if (fr.size() < fn)
        {
            fr.push_back(pg[i]);
        }
        else
        {
            int j = predict(pg, fr, pn, i + 1);
            fr[j] = pg[i];
        }
    }
    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << pn - hit << endl;
}
int main()
{
    int n;
    cin >> n;
    int capacity;
    cin >> capacity;
    int pages[n];
    for (int i = 0; i < n; i++)
    {
        cin >> pages[i];
    }
    optimalPage(pages, n, capacity);
    return 0;
}
