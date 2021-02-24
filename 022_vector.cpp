#include <bits/stdc++.h>
using namespace std;

void fun(int n)
{
    vector<int> ans;
    ans.push_back(1);            // vector to store the result
    for (int i = 2; i <= n; i++) // we will multiply number i from the end of vector
    {
        int sz = ans.size();
        int prev = 0;
        for (int j = sz - 1; j >= 0; j--)
        {
            int temp = i * ans[j] + prev; //  add prev carry too

            if (temp >= 10) //  if greater then 10 then add only ones digit
            {
                int ones = temp % 10;
                ans[j] = ones;
                prev = temp / 10;
            }
            else
            {
                ans[j] = temp;
                prev = 0;
            }
        }
        if (prev > 0) // put all places of prev carry at last in each indices
        {
            while (prev)
            {
                ans.insert(ans.begin(), prev % 10);
                prev = prev / 10;
            }
        }
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        fun(n);
    }
    return 0;
}