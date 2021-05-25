class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1,mid;
        while(l<=r)
        {
            mid = (r-l)/2+l;
            if(nums[mid]==target)
                return mid;
            if(nums[l]<=nums[mid])// means left side is sorted
            {
                if(nums[l]<=target && nums[mid]>target)// element can be in left side
                    r = mid - 1;
                else//element can be in right side
                    l = mid + 1;
            }
            else
            {
                if(nums[mid]<target && nums[r]>=target)
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};