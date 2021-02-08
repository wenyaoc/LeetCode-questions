// 执行用时: 4 ms
// 内存消耗: 12.5 MB

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res;
        std::sort(nums.begin(), nums.end()); 
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i-1]) continue; 
            if (nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if (nums[i] + nums[n-1] + nums[n-2] + nums[n-3] < target) continue;

            int newTarget = target - nums[i];
            for (int j = i+1; j < n - 2; j++) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                if (nums[j] + nums[j+1] + nums[j+2] > newTarget) break;
                else if (nums[j] + nums[n-1] + nums[n-2] < newTarget) continue;

                int left = j + 1;
                int right = n - 1;
                while (left < right) {
                    int total = nums[j] + nums[right] + nums[left] ;
                    if (total < newTarget) {
                        left++;
                        while (left < right && nums[left] == nums[left - 1]) left++; 
                    } else if (total > newTarget) {
                        right--;
                        while (left < right && nums[right] == nums[right + 1]) right--; 
                    } else {
                        res.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++; 
                        while (left < right && nums[right] == nums[right + 1]) right--; 
                    } 
                }
            }
        }
        return res;
    }
};
