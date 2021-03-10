void fun(string s, vector<string> &a, int l, int r)
{
    if (l == r) // if index is last one just append the element
    {
        a.push_back(s);
    }
    else
    {
        for (int i = l; i <= r; i++) //from l index to r , interchange l to ith and recall the function for further changes
        {
            swap(s[l], s[i]);
            fun(s, a, l + 1, r);
            swap(s[l], s[i]);
        }
    }
}
vector<string> find_permutation(string s)
{
    vector<string> a;
    fun(s, a, 0, s.size() - 1);
    sort(a.begin(), a.end());
    return a;
}