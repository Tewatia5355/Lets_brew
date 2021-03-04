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
        int maxr = intervals[s][1];                            // what is the max range we are currently having
        while (i < int_siz - 1 && maxr >= intervals[i + 1][0]) // i inside the  loop and max range is less then next elements start range
        {
            if (maxr < intervals[i + 1][1]) // we check for new max range
                maxr = intervals[i + 1][1];
            ++i;
        }
        vector<int> temp;
        temp.push_back(intervals[s][0]);                                 // starting element
        temp.push_back(maxr < intervals[i][1] ? intervals[i][1] : maxr); // checking for ending range
        ans.push_back(temp);                                             // making a new range and inserting them in ans
        s = ++i;                                                         // as we got the new range now we increse i and check for another range
        // we incresed i as in above while loop we are checking with condition i+1, so we have current i
    }
    return ans;
}