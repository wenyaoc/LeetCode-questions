class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int num = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                res.push_back(nums[i]);
                num++;
            } 
        }
        nums = res;
        return num;
    }
};
