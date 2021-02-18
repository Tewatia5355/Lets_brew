void nextPermutation(vector<int> &nums)
{
    int x = 0, flag = 0;
    if (nums.size() <= 1)
        return;
    for (int i = nums.size() - 1; i > 0; --i) // find a point whereyour last peak in array is
    {
        if (nums[i] > nums[i - 1])
        {
            x = i - 1;
            flag = 1;
            break;
        }
    }
    //value of x peak index - 1
    // cout<<x<<" ";
    if (flag == 0) // if number is fully decresing... we need to reverse it and make fully increasing
    {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
    else
    {
        flag = 1;
        int i = nums.size() - 1;
        while (i > (x + 1)) // find a point till when the nums[x] is less then right side of peak! just greater
        {
            if (nums[i] > nums[x])
            {
                flag = 0;
                break;
            }
            --i;
        }
        swap(nums[i], nums[x]); // swap that greater number to x
        i = x + 1;
        int j = nums.size() - 1;
        while (i <= j) // as the elements from peak to right are all descending one! swap them to make them fully increasing!!
        {
            swap(nums[i], nums[j]);
            ++i;
            --j;
        }
    }
}