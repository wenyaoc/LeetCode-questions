class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        int target = nums.size() - k;
        while (l < r) {
            int mid = partition(nums, l, r);
            if (mid == target) return nums[mid];
            else if (mid > target) r = mid - 1;
            else l = mid + 1;
        }
        return nums[l];
    }

    int partition(vector<int>&nums, int l, int r) {
        int i = l + 1, j = r;
        medianOfThree(nums, l, r);
        while(1) {
            while (j > i && nums[j] >= nums[l]) j--;
            while (i < j && nums[i] <= nums[l]) i++;
            if (i == j) break;
            swap(nums[i], nums[j]);
        }
        j = nums[j] < nums[l] ? j : j-1;
        swap(nums[j], nums[l]);
        return j;
    }

    // swap the medimum one to the frount;
    void medianOfThree(vector<int>&nums, int l, int r) {
        int median = (l + r) >> 1;
        if (nums[l] > nums[median]) swap(nums[l], nums[median]);
        if (nums[median] > nums[r]) swap(nums[r], nums[median]);
        if (nums[l] < nums[median]) swap(nums[l], nums[median]);
    }
};
