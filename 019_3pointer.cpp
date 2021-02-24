vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        // cout<<a[i]<<" "<<b[j]<<" "<<c[k]<<"\n";
        if (a[i] < b[j] && a[i] < c[k])
        {
            ++i;
            while (i < n1 && a[i] == a[i - 1])
                ++i;
        }
        else if (b[j] < a[i] && b[j] < c[k])
        {
            ++j;
            while (j < n2 && b[j] == b[j - 1])
                ++j;
        }
        else if (c[k] < a[i] && c[k] < b[j])
        {
            ++k;
            while (k < n3 && c[k] == c[k - 1])
                ++k;
        }
        else if (a[i] > b[j] && b[j] == c[k])
        {
            ++j;
            while (j < n2 && b[j] == b[j - 1])
                ++j;
        }
        else if (b[j] > a[i] && a[i] == c[k])
        {
            ++k;
            while (k < n3 && c[k] == c[k - 1])
                ++k;
        }
        else if (c[k] > a[i] && a[i] == b[j])
        {
            ++i;
            while (i < n1 && a[i] == a[i - 1])
                ++i;
        }
        else //if(a[i]==b[j] && a[i]==c[k])
        {

            // cout<<"g\n";
            ans.push_back(a[i]);
            ++i;
            while (i < n1 && a[i] == a[i - 1])
                ++i;
            ++j;
            while (j < n2 && b[j] == b[j - 1])
                ++j;
            ++k;
            while (k < n3 && c[k] == c[k - 1])
                ++k;
        }
    }
    return ans;
}