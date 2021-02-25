// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

class Solution
{

public:
    int trappingWater(int arr[], int n)
    {
        // Code here
        int *r = new int[n]; // array stores maximum element from the right side of array
        int *l = new int[n]; // array stores maximum element from the left side of array
        l[0] = arr[0], r[n - 1] = arr[n - 1];
        for (int i = 1, j = n - 2; i < n; i++, j--) // building l and r array
        {
            if (l[i - 1] < arr[i])
                l[i] = arr[i];
            else
                l[i] = l[i - 1];

            if (r[j + 1] < arr[j])
                r[j] = arr[j];
            else
                r[j] = r[j + 1];
        }
        int sum = 0;
        for (int i = 0; i < n; i++) // main crux of algo -> at any index check which wall is smaller , left or right , from that subtract arr[i] and check it is greater then 0
        {
            int temp = min(r[i], l[i]) - arr[i];
            sum += temp > 0 ? temp : 0;
        }
        return sum;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    //testcases
    cin >> t;

    while (t--)
    {
        int n;

        //size of array
        cin >> n;

        int a[n];

        //adding elements to the array
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends