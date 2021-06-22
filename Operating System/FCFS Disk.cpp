
#include <bits/stdc++.h>
using namespace std;

void FCFS(int arr[], int head, int size)
{
    int seek_count = 0;
    int distance, cur_track;
    for (int i = 0; i < size; i++)
    {
        cur_track = arr[i];
        // calculate absolute distance
        distance = abs(cur_track - head);
        // increase the total count
        seek_count += distance;
        // accessed track is now new head
        head = cur_track;
    }
    cout << "Total number of seek operations = "
         << seek_count << endl;
}
// Driver code
int main()
{
    // request array
    int size;
    cin >> size;
    cout << "Size " << size << endl;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int head;
    cin >> head;
    cout << "head " << head << endl;
    FCFS(arr, head, size);
    return 0;
}