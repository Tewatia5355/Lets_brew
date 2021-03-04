// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> mat[i][j];
        int r;
        cin >> r;
        cout << kthSmallest(mat, n, r) << endl;
    }
    // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
    return 0;
}
// } Driver Code Ends

int fun(int mat[MAX][MAX], int n, int k, int mid) // count the elements less then mid in matrix
{
    int i = n - 1;          // starting with ending row
    int j = 0;              // starting with first col
    int cnt = 0;            // cnt of elements
    while (i >= 0 && j < n) // loop termination conditions
    {
        if (mat[i][j] > mid) // if first element of mat is greater then mid then reduce row
            i--;
        else //if the element is greater then all the elements above this row will be added to row, also col is increased by 1
        {
            cnt += i + 1;
            j++;
        }
    }
    return cnt; // return the cnt
}

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    int mx = mat[n - 1][n - 1];                          // max element in mat
    int mn = mat[0][0] /*min element in mat*/, ans = -1; // answer to be returned
    while (mn <= mx)                                     // while the loop goes to find mid which is the anser afterall
    {
        int mid = mn + (mx - mn) / 2;  // find mid
        int num = fun(mat, n, k, mid); // cnt elements less then this or not
        if (num < k)                   // if elements are less then k so we will increase min to mid+1
            mn = mid + 1;
        else // we wont break at n==k, as this might give mid which is not in mat, so let whole loop to finish
        {
            ans = mid;    // store possible ans
            mx = mid - 1; // reduce max to mid - 1
        }
    }
    return ans; // return the answer
}

//Time complexity : O(nlog(max-min))
//space complexity : O(1)