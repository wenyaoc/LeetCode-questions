class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int curr = l;
        while (curr <= r) {
            if (nums[curr] == 0) {
                swap(nums[curr], nums[l]);
                l++;
                curr++;
            } else if (nums[curr] == 1) {
                curr++;
            } else {
                swap(nums[curr], nums[r]);
                r--;
            }
        }
    }
};
