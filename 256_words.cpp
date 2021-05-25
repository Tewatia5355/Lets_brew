// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void fun(int n, vector<string> &dict, vector<string> &ans, string s, int x, int y, string t)
    {
        if (y == s.size() + 1) // if y is out of bound
        {
            string z = t;
            t.erase(remove(t.begin(), t.end(), ' '), t.end()); // making sure every char of s is present in t
            if (s == t)
                ans.push_back(z.substr(0, z.size() - 1)); // then only pushing the value to this
        }
        else if (x == y)
            return;
        else
        {
            string chk = s.substr(x, y - x);
            for (int i = 0; i < n; i++)
            {
                if (chk == dict[i]) // if in dict
                {
                    fun(n, dict, ans, s, y, y + 1, t + dict[i] + " "); // call the next word from this
                    break;
                }
            }
            fun(n, dict, ans, s, x, y + 1, t); // else increase just y
        }
    }

    vector<string> wordBreak(int n, vector<string> &dict, string s)
    {
        vector<string> ans;
        // make sure that every char of s is present in t
        fun(n, dict, ans, s, 0, 1, "");
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
        int n;
        vector<string> dict;
        string s;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            dict.push_back(s);
        }
        cin >> s;

        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if (ans.size() == 0)
            cout << "Empty\n";
        else
        {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++)
                cout << "(" << ans[i] << ")";
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends