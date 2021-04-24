// Assignment DAA LAB
// Question 2
// Saharsh Ananta Jaiswal
// 18CS8061

// ------------------ Count Sort Implementation ----------------------

/*
Counting Sort is a sorting technique based on keys between a specefic range. It works by counting the number of objects having distinct key values. Then doing some arithmetic to calculate the position of each object in the output sequence

*/

// -------------------CODE --------------------

#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[], int n)
{
    int arr1[10];
    int x = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > x)
            x = arr[i];
    }
    int count_arr[10];
    for (int i = 0; i <= x; ++i)
    {
        count_arr[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count_arr[arr[i]]++;
    }
    for (int i = 1; i <= x; i++)
    {
        count_arr[i] += count_arr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
}
int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
