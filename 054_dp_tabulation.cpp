#include <bits/stdc++.h>
using namespace std;
// see video for implementation
void fun(string a)
{
    int ssz = a.size();
    vector<vector<int>> dp(ssz, vector<int>(ssz, 0));

    for (int i = 0; i < ssz; i++)
        dp[i][i] = 1;

    int ml = 1, ms = 0;

    for (int i = ssz - 2; i >= 0; i--)
    {
        if (a[i] == a[i + 1])
        {
            dp[i][i + 1] = 1;
            ml = 2;
            ms = i;
        }
    }

    for (int i = 2; i < ssz; i++)
    {
        for (int j = 0; j < ssz - i; j++)
        {
            if (a[j] == a[j + i] && dp[j + 1][i + j - 1])
            {
                dp[j][i + j] = 1;
                if (ml < (i + 1))
                {
                    ml = i + 1;
                    ms = j;
                }
            }
        }
    }

    for (int i = ms; i < ml + ms; i++)
        cout << a[i];
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string rev;
        cin >> rev;
        fun(rev);
    }
    return 0;
}