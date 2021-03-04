// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to calculate span
// price[]: price array in input
// n: size of array
vector <int> calculateSpan(int price[], int n)
{
   // Your code here
   vector<int> ans;
   stack<int> s;
   for(int i = 0;i<n;i++)
   {
        if(s.empty())
            ans.push_back(-1);            
        else if(s.top().first > price[i])
            ans.push_back(s.top().second);
        else
        {
            while(!s.empty() && s.top().first<=price[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);            
            else
                ans.push_back(s.top().second);
        }
        s.push(make_pair(price[i],i));
   }
   for(int i = 0;i<n;i++)
    ans[i] = i - ans[i];
   return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		
		vector <int> s = calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends