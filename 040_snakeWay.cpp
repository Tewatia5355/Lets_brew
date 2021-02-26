// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    int first(vector<vector<int>> arr, int r, int e) // find the index of first one in that row
    {
        for (int i = 0; i < e; i++)
        {
            if (arr[r][i] == 1)
                return i;
        }
        return e;
    }
    int rowWithMax1s(vector<vector<int>> arr, int n, int m)
    {
        int j = first(arr, 0, m), ans = 0; // index of first 1 in 0th row
        if (j == 0)
            return 0;
        for (int i = 1; i < n; i++) // if another row has smaller index then change that
        {
            int temp = first(arr, i, j);
            if (temp < j)
            {
                j = temp;
                ans = i;
            }
            if (j == 0)
                return i;
        }
        if (j == m) // no 1 present then return -1
            return -1;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends