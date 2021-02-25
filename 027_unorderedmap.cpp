#include <bits/stdc++.h>
using namespace std;

void fun(int *a, int *b, int m, int n)
{
    if (m < n)
    {
        cout << "No\n";
        return;
    }
    unordered_map<int, int> mp, mo;
    for (int i = 0; i < m; i++)
        mp[a[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (mp.count(b[i]))
        {
            mp[b[i]]--;
            mo[b[i]] = mp[b[i]];
        }
        else
        {
            cout << "No\n";
            return;
        }
    }
    for (auto it = mo.begin(); it != mo.end(); it++)
    {
        if (it->second != 0)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        int *a = new int[m];
        int *b = new int[n];
        for (int i = 0; i < m; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        fun(a, b, m, n);
    }
    return 0;
}