string countAndSay(int nn)
{
    if (nn == 1)
        return "1";
    string prev = countAndSay(nn - 1); //store prev string
    long long i = 0, sz = prev.size();
    string ans = ""; //ans string
    for (long long x = 0; x < sz;)
    {
        int cnt = 1;
        int ele = prev[x] - 48;
        while (x < (sz - 1) && prev[x] == prev[x + 1]) // count the duplicates
        {
            cnt++;
            x++;
        }
        if (prev[x] == ele && x == (sz - 1)) // check for last element in prev
            x++;
        ans += to_string(cnt);
        ans += to_string(ele);
        x++;
    }
    return ans; // return ans
}