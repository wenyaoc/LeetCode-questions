class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 复制一遍数组
        int n = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());

        vector<int> res;
        stack <int> stk;
        // 从右往左，维护一个单调递增栈
        for (int i = 2 * n - 1; i >= 0; i --) {
            while (!stk.empty() && nums[i] >= stk.top()) 
                stk.pop();
            if (stk.empty()) {
                if (i <= n - 1) res.push_back(-1);
            } else {
                if (i <= n - 1) res.push_back(stk.top());
            }
            stk.push(nums[i]);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
