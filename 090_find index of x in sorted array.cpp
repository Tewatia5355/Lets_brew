// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    // code here
    int l = 0, r = n-1,fg = 0,mid;
    while(l<=r)
    {
        mid = (r-l)/2+l;
        if(arr[mid]==x)
        {
            fg = 1;
            break;
        }
        else if(arr[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    if(fg==0)
        return vector<int>(2,-1);
    int temp = mid;
    // cout<<mid<<"\n";
    vector<int> a;
    while(mid>=0)
    {
        if(arr[mid]!=x)
        {
            a.push_back(mid+1);
            break;
        }
        mid -= 1;
    }
    if(mid==-1)
        a.push_back(0);
    mid = temp;
    while(mid<n)
    {
        if(arr[mid]!=x)
        {
            a.push_back(mid-1);
            break;
        }
        mid += 1;
    }
    if(mid==n)
        a.push_back(mid-1);
    return a;
}