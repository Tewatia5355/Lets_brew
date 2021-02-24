// order DON'T MATTER USE SET

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends

// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers

//////// it will have less number of nested for loops
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_set<int> mp;
    int ans = 0;

    for (int i = 0; i < n; i++) // ADD ALL ELEMENTS IN SET
        mp.insert(arr[i]);

    for (int i = 0; i < n; i++) // AGAIN ITERATE
    {
        if (mp.find(arr[i] - 1) == mp.end()) // IF THE ELEMENT IS STARTING ELEMENT OF SUB SEQUENCE THEN ONLY COUNT THE FURTHER ELEMENTS
        {
            int j = arr[i];
            while (mp.find(j) != mp.end()) // COUNT OF FURTHER ELEMENTS
            {
                j++;
            }

            ans = max(ans, j - arr[i]);
        }
    }
    return ans;
}