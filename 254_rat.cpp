// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
public:

	void fun(vector<vector<int>> &m, vector<string> &ans, string t, int n, int x, int y)
	{
		if (x == (n - 1) && y == (n - 1) && m[x][y] == 1)
			ans.push_back(t);
		if (x < 0 || y < 0 || x >= n || y >= n)
			return;
		if (m[x][y] == 0)
			return;
		m[x][y] = 0;
		fun(m, ans, t + "D", n, x + 1, y);
		fun(m, ans, t + "U", n, x - 1, y);
		fun(m, ans, t + "L", n, x, y - 1);

		fun(m, ans, t + "R", n, x, y + 1);

		m[x][y] = 1;
	}

	vector<string> findPath(vector<vector<int>> &m, int n) {
		vector<string> ans;
		fun(m, ans, "", n, 0, 0);
		sort(ans.begin(), ans.end());
		return ans;
	}
};




// { Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> m(n, vector<int> (n, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> m[i][j];
			}
		}
		Solution obj;
		vector<string> result = obj.findPath(m, n);
		if (result.size() == 0)
			cout << -1;
		else
			for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
		cout << endl;
	}
	return 0;
}  // } Driver Code Ends