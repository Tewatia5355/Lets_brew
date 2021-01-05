#include <bits/stdc++.h>
using namespace std;

void func(int *a, int n)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] >= 0 && a[j] < 0)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
        else if (a[i] < 0)
            i++;
        else if (a[j] >= 0)
            j--;
    }
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    func(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}