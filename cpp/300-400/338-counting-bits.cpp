class Solution {
public:
    vector<int> countBits(int num) {
        int i = 1;
        vector<int> ans(num + 1);
        for (int i = 0; i <= num; i++) {
            if (i % 2 == 0) 
                ans[i] = ans[i / 2];
            else 
                ans[i] = ans[i / 2] + 1;
        }
        return ans;
    }
};
