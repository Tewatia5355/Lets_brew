bool comp(vector<int> a, vector<int> b)
{
    if (a[0] < b[0])
        return true;
    if (a[0] == b[0])
        return (a[1] < b[1]);
    return false;
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), comp);
    vector<vector<int>> ans;
    int i = 0;
    int s = 0;
    int int_siz = intervals.size();
    while (i < int_siz)
    {
        int maxr = intervals[s][1];

        while (i < int_siz - 1 && maxr >= intervals[i + 1][0])
        {
            if (maxr < intervals[i + 1][1])
                maxr = intervals[i + 1][1];
            ++i;
        }
        vector<int> temp;
        temp.push_back(intervals[s][0]);
        temp.push_back(maxr < intervals[i][1] ? intervals[i][1] : maxr);
        ans.push_back(temp);
        s = ++i;
    }
    return ans;
}