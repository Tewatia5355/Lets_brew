int minJumps(int arr[], int n)
{
    int i = 0, jump = 0;
    while (i < n)
    {
        int s = arr[i];
        if (i == (n - 1))
            return jump;
        if (s == 0)
            return -1;
        else
        {
            int l = i + 1, r = i + s, cm = 0, ci = -1;
            // cout<<i<<" "<<r<<" "<<jump<<"\n";
            ++jump;
            if (r >= (n - 1))
                return jump;
            while (l <= r)
            {
                if (arr[l] + l > cm)
                {
                    cm = arr[l] + l;
                    ci = l;
                }
                if (arr[l] + l >= (n - 1))
                {
                    ++jump;
                    return jump;
                }
                l++;
            }
            i = ci;
        }
    }
}