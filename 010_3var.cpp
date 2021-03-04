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
            int l = i + 1, r = i + s, cm = 0, ci = -1; // making window from l+1 to l+s
            //cm -> max range we can jump, ci -> index of that jump
            ++jump;           // add 1 jump
            if (r >= (n - 1)) // if window exceed the last element return jumps
                return jump;
            while (l <= r)
            {
                if (arr[l] + l > cm) // checking for max range jump we can make and store it in cm
                {
                    cm = arr[l] + l;
                    ci = l;
                }
                if (arr[l] + l >= (n - 1)) // if we got element which can exceed last element then increase jump and return that
                {
                    ++jump;
                    return jump;
                }
                l++; // increase i
            }
            i = ci; // start i from ci and make new window
        }
    }
}