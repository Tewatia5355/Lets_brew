// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // function to find the triplet which sum to x
    // arr[] : The input Array
    // N : Size of the Array
    // X : Sum which you need to search for

    bool find3Numbers(int arr[], int n, int x)
    {
        sort(arr, arr + n); //sort the array
        int i = n - 1;
        while (i >= 0 && arr[i] > x) // last element greater then x is not valid
            i--;
        if (i <= 1)
            return false;
        for (; i >= 2; i--) // set last element as pivot
        {
            int xx = 0, y = i - 1; // 2 pointer in between start and pivot
            while (xx < y)
            {
                int sum = arr[i] + arr[xx] + arr[y];
                if (sum < x)
                    xx++;
                else if (sum > x)
                    y--;
                else
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, sum;
        cin >> N >> sum;
        int i, A[N];
        for (i = 0; i < N; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, N, sum) << endl;
    }
}
// } Driver Code Ends