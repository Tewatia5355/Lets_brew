// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
typedef long long ll;
class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(int *arr, int n)
    {
        // code here
        ll ans = INT_MIN;

        ll pos = 1, neg = 1, chk = 1;
        // always make sure that pos>1 and neg < 1 and if arr[i] == 0 both becomes 1
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                pos = pos * arr[i];
                neg = min(neg * arr[i], chk); //used chk as ll can't compare to int
                if (ans < pos)
                    ans = pos;
            }
            else if (arr[i] < 0)
            {
                ll temp = neg; // req to store the previous val!
                neg = pos * arr[i];
                pos = max(temp * arr[i], chk);
                if (ans < pos)
                    ans = pos;
            }
            else
            {
                pos = 1;
                neg = 1;
            }
        }
        return ans; // give ans
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends