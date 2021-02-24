bool subArrayExists(int arr[], int n)
{
    unordered_map<int, int> ind;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0) // if sum is zero
            return true;
        if (ind.count(sum)) // if the sum is previous;y occured then it means we have subarray in between those both sum
        {
            return true;
        }
        ind[sum]++;
    }
    return false;
}