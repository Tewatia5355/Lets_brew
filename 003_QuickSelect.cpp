// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


//User function template for C++

// arr : given array
// l : starting index of the array i.e 0
// r : ending index of the array i.e size-1
// k : find kth smallest element and return using this function
int kthSmallest(int arr[], int l, int r, int k) {
    //code here
    
    if(l>=r)
    {
        return arr[k-1];
    }
    else
    {
        int pivot = arr[l];
            int i = r+1;
            
            for(int j = r;j>=l+1;j--)
            {
                if(pivot<=arr[j])
                {
                    i--;
                    swap(arr[i],arr[j]);
                }   
            }
        if(i == l && i!=k-1) 
            return kthSmallest(arr,i+1,r,k);
        else 
        {
            swap(arr[i-1],arr[l]);
            if(i-1 == k-1) 
                return arr[k-1];
            else 
            {
                if(k-1 > i-1)
                    return kthSmallest(arr,i,r,k);
                else 
                    return kthSmallest(arr,l,i-2,k);
            }
        }
        
    }
    
}