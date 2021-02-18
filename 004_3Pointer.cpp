void sort012(int a[], int n)
{
    int i = 0;
    int j = 0;
    int k = n-1;
    while(j<=k)
    {
        if(a[j]==2)
        {
            swap(a[j],a[k]);
            k--;
        }
        else if(a[j]==0)
        {
            swap(a[j],a[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
}
