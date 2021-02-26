// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void rr(vector<vector<int>> m, vector<int> &a, int sr, int sc, int ec)
    {
        for (int i = sc; i < ec; i++)
            a.push_back(m[sr][i]);
    }
    void rl(vector<vector<int>> m, vector<int> &a, int sr, int sc, int ec)
    {
        for (int i = sc - 1; i >= ec; i--)
            a.push_back(m[sr - 1][i]);
    }
    void cd(vector<vector<int>> m, vector<int> &a, int sr, int sc, int er)
    {
        for (int i = sr; i < er; i++)
            a.push_back(m[i][sc - 1]);
    }
    void cu(vector<vector<int>> m, vector<int> &a, int sr, int sc, int er)
    {
        for (int i = sr - 1; i >= er; i--)
            a.push_back(m[i][sc]);
    }

    vector<int> spirallyTraverse(vector<vector<int>> m, int r, int c)
    {
        // reduce dimension of matrix printing and check whenever matrix diminises
        vector<int> a;
        int rn = 0, cn = 0;
        while (rn < r && cn < c)
        {
            rr(m, a, rn, cn, c);
            rn++;
            if (rn >= r)
                break;
            cd(m, a, rn, c, r);
            c--;
            if (cn >= c)
                break;
            rl(m, a, r, c, cn);
            r--;
            if (rn >= r)
                break;
            cu(m, a, r, cn, rn);
            cn++;
        }
        return a;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++)
        {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends