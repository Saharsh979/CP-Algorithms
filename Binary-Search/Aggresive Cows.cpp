#include <bits/stdc++.h>
using namespace std;

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    int i = 0;
    int j = 0;
    int l = 0;
    while (i != n || j != m)
    {
        if (i != n && j != m)
        {
            if (arr1[i] > arr2[j])
            {
                j++;
                l++;
                if (l == k)
                    return arr2[j - 1];
            }
            else
            {
                i++;
                l++;
                if (l == k)
                    return arr1[i - 1];
            }
        }
        else if (i == n)
        {
            j++;
            l++;
            if (l == k)
                return arr2[j - 1];
        }
        else
        {
            i++;
            l++;
            if (l == k)
                return arr1[i - 1];
        }
    }
}

int threeSumClosest(vector<int> arr, int target)
{
    // Your code goes here
    int res = INT_MIN, minDiff = INT_MAX;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {

        int sum = arr[i];
        int l = i + 1, h = arr.size() - 1;

        while (l < h)
        {
            int temp = sum + arr[l] + arr[h];

            int diff = abs(target - temp);

            if (diff == 0)
                return temp;
            else if (temp < target)
                l++;
            else
                h--;

            if (minDiff == diff)
            {
                res = max(res, temp);
            }
            else
            {
                minDiff = min(diff, minDiff);
                if (minDiff == diff)
                    res = temp;
            }
        }
    }

    return res;
}

string res = "";
unordered_map<char, int = ""> mp;
int l = 0, counter = 0, len = INT_MAX;
for (char c : t)
    ++mp[c];
for (int r = 0; r < s.size(); ++r)
{
    if (--mp[s[r]] >= 0)
        ++counter; // moving window
    while (counter == t.size())
    { // desire substring
        if (len > r - l + 1)
        {
            len = r - l + 1;
            res = s.substr(l, len);
        }
        if (++mp[s[l]] > 0)
            --counter; // shrinking of window
        ++l;
    }
}
// if (res=="") return "-1";
return res == "" ? "-1" : res;
}