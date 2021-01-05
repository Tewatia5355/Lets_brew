#include <iostream>
using namespace std;
int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int tt = a[n - 1];
        for (int i = n - 1; i >= 1; i--)
        {
            a[i] = a[i - 1];
        }
        a[0] = tt;
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}