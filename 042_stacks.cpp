// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this method*/

int mh(int *arr, int n) // finding max area of histogram
{
    vector<int> smr, sml;
    stack<pair<int, int>> s1, s2;

    //NSR
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1.empty())
            smr.push_back(n);
        else if (s1.top().first < arr[i])
            smr.push_back(s1.top().second);
        else
        {
            while (!s1.empty() && s1.top().first >= arr[i])
                s1.pop();
            if (s1.empty())
                smr.push_back(n);
            else
                smr.push_back(s1.top().second);
        }

        s1.push(make_pair(arr[i], i));
    }
    reverse(smr.begin(), smr.end());

    //NSL
    for (int i = 0; i < n; i++)
    {
        if (s2.empty())
            sml.push_back(-1);
        else if (s2.top().first < arr[i])
            sml.push_back(s2.top().second);
        else
        {
            while (!s2.empty() && s2.top().first >= arr[i])
                s2.pop();
            if (s2.empty())
                sml.push_back(-1);
            else
                sml.push_back(s2.top().second);
        }

        s2.push(make_pair(arr[i], i));
    }

    int data, mx = 0;
    for (int i = 0; i < n; i++)
    {
        data = (smr[i] - sml[i] - 1) * arr[i]; // gets area corresponding to a building and its width
        if (mx < data)
            mx = data;
    }
    return mx;
}

int maxArea(int M[MAX][MAX], int n, int m)
{

    int *arr = new int[m]; // covert and add each row iteratively to make 2D -> 1D matrix
    for (int i = 0; i < m; i++)
    {
        arr[i] = M[0][i];
    }
    vector<int> ans;
    ans.push_back(mh(arr, m));
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 0)
                arr[j] = 0;
            else
                arr[j] += M[i][j];
        }
        ans.push_back(mh(arr, m));
    }
    return *max_element(ans.begin(), ans.end()); // find max element in ans and return that
}
