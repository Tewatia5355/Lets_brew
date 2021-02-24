//HERE ORDER MATTERS

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
int findLongestConseqSubseq(int arr[], int n)
{
    unordered_map<int, pair<int, int>> mp; // MAP TO STORE BACK AND FRONT
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        mp[arr[i]] = make_pair(arr[i], arr[i]);
        if (mp.count(arr[i] - 1)) // IF LAST IS PRESENT
        {
            mp[arr[i]].first = mp[arr[i] - 1].first;
        }
        if (mp.count(arr[i] + 1)) // IF FRONT IS PRESENT
        {
            mp[arr[i]].second = mp[arr[i] + 1].second;
        }
        int back = mp[arr[i]].first;
        for (int j = arr[i] - 1; j >= back; j--) // UPDATE FRONT OF ALL THE BACK ELEMENTS IN BETWEEN
        {
            mp[j].second = mp[arr[i]].second;
            // cout<<"min "<<mp[j].second<<" "<<j<<"\n";
        }
        int front = mp[arr[i]].second;
        for (int j = arr[i] + 1; j <= front; j++) // UPDATE BACK OF ALL THE FRONT ELEMENTS IN BETWEEN
        {
            mp[j].first = mp[arr[i]].first;
            // cout<<"max "<<mp[j].first<<" "<<j<<"\n";
        }
        //   cout<<mp[arr[i]].second<<" - "<<mp[arr[i]].first<<"\n";
        if (ans <= (mp[arr[i]].second - mp[arr[i]].first + 1)) // COMPARE AND STORE ANS
            ans = mp[arr[i]].second - mp[arr[i]].first + 1;
    }
    return ans;
}