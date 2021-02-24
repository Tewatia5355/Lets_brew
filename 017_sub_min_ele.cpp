//Subtract minimum element from each element and store the max result in the array for use...

int maxProfit(vector<int> &prices)
{
    int mx = prices[0], maxr = INT_MIN;
    for (int i = 0; i < prices.size(); ++i)
    {
        if (prices[i] < mx)
            mx = prices[i];
        else
        {
            maxr = max(maxr, prices[i] - mx);
        }
    }
    return maxr;
}