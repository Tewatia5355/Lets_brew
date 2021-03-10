int countBinarySubstrings(string s)
{
    int curr = 1, prev = 0, cnt = 0;
    auto chk = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if (chk == s[i])
        {
            curr++;
        }
        else
        {

            chk = s[i];
            cnt += min(prev, curr);
            prev = curr;
            curr = 1;
        }
    }
    cnt += min(prev, curr);
    return cnt;
}