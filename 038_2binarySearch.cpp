bool searchMatrix(vector<vector<int>> &m, int x)
{
    int r = m.size();
    int c = m[0].size();
    int sx = 0, ex = r - 1;
    while (sx < ex) // here we will find the row to be searched
    {
        int mid = (sx + ex) / 2;
        if (x < m[mid][0]) // if x is less then first element then last element
            ex = mid - 1;
        else if (x > m[mid][c - 1]) // if x is greater then last element of row then next row pls
            sx = mid + 1;
        else // if in between then this is the row
        {
            sx = mid;
            break;
        }
    }
    int sy = 0, ey = c - 1;
    while (sy <= ey) // for that row we will apply normal binary search
    {
        int mid = (sy + ey) / 2;
        if (x < m[sx][mid])
            ey = mid - 1;
        else if (x > m[sx][mid])
            sy = mid + 1;
        else
            return true;
    }
    return false;
}