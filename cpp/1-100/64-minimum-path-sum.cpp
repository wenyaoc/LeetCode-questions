class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(); // m, n >= 1
        vector<int> dp (n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) { // first col and first row
                    if (i != 0) dp[j] = dp[j] + grid[i][j];
                    else if (j != 0) dp[j] = dp[j-1] + grid[i][j];
                    else dp[0] = grid[0][0];
                } else {
                    dp[j] = grid[i][j] + min(dp[j], dp[j-1]);
                }
            }
        }
        return dp[n-1];
    }
};
