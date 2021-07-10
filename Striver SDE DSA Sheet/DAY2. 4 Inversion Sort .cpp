// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>

// } Driver Code Ends
//User function Template for C

// arr[]: Input Array
// N : Size of the Array arr[]
long long inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long temp[N];
    return _mergesort(arr, temp, 0, N - 1);
}
long long _mergesort(long long arr[], long long temp[], long long left, long long right)
{
    long long mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count += _mergesort(arr, temp, left, mid);
        inv_count += _mergesort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{

    long long i, j, k;
    long long inv_count = 0;
    i = left;
    j = midl;
    k = left;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j]++;
            inv_count = inv + (mid - i);
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }
    return inv_count;
}

// { Driver Code Starts.

long long main()
{

    long long T;
    scanf("%ld", &T);

    while (T--)
    {
        long long N;
        scanf("%ld", &N);

        long long A[N];
        for (long long i = 0; i < N; i++)
        {
            scanf("%ld", &A[i]);
        }

        prlong long f("%ld\n", inversionCount(A, N));
    }

    return 0;
}
// } Driver Code Ends