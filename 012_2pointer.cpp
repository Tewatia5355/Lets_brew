void merge(int arr1[], int arr2[], int n, int m)
{
    // code here
    int i = n - 1;
    int j = 0;

    // this loop helps in swapping the elements and putting elements in right array
    // hence all elements in array 1 is less then those of array 2
    while (j < m && i >= 0 && arr1[i] > arr2[j])
    {
        swap(arr1[i], arr2[j]);
        --i;
        ++j;
    }
    // sort both arrays respectively;
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}