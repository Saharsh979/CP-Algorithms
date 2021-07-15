void recurse(vector<int> arr, vector<int> res, int i, int size, int sum)
{
    if (i == size - 1)
    {
        res.push_back(sum);
        return;
    }
    else
    {
        i = i + 1;
        recurse(arr, res, i, size, sum);
        recurse(arr, res, i, size, sum + arr[i]);
    }
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    int size = N;
    vector<int> res;
    int sum = 0;
    int index = -1;
    recurse(arr, res, index, size, sum);

    return res;
}