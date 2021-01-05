#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m1;
        cin >> n >> m1;
        unordered_map<int, pair<int, int>> m;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            if (m.find(temp) == m.end())
                m.insert({temp, make_pair(1, 0)});
            else
                m[temp].first++;
        }
        for (int i = 0; i < m1; i++)
        {
            int temp;
            cin >> temp;
            if (m.find(temp) == m.end())
                m.insert({temp, make_pair(0, 1)});
            else
                m[temp].second++;
        }
        int ans = m.size();
        cout << ans << "\n";
    }
    return 0;
}