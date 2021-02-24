int getPairsCount(int arr[], int n, int k)
{
    // code here

    unordered_map<int, int> freq;
    int sum = 0;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++; //count freq
    for (int i = 0; i < n; i++)
    {
        sum += freq[k - arr[i]];  // see the no. of connection from this element to the req. no of elements
        if (k - arr[i] == arr[i]) // if element is same again, then we remove self loop
            sum--;
    }
    return sum / 2; // as each pair is counted twice!!
}