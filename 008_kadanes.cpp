int maxSubarraySum(int arr[], int n)
{

    int mx = 0, curr = 0;
    for (int i = 0; i < n; i++)
    {
        curr += arr[i];
        if (curr < 0)
            curr = 0;
        if (curr > mx)
            mx = curr;
    }
    return mx;
}