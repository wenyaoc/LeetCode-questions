class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m? grid[0].size(): 0;
        int currArea = 0;
        int maxArea = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    currArea = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty()) {
                        auto [a,b] = island.top();
                        island.pop();
                        currArea++;
                        if (b-1 >= 0 && grid[a][b-1]) {
                            island.push({a, b-1});
                            grid[a][b-1] = 0;
                        } 
                        if (b+1 < n && grid[a][b+1]) {
                            island.push({a, b+1});
                            grid[a][b+1] = 0;
                        }
                        if (a+1 < m && grid[a+1][b]) {
                            island.push({a+1, b});
                            grid[a+1][b] = 0;
                        }
                        if (a-1 >= 0 && grid[a-1][b]) {
                            island.push({a-1, b});
                            grid[a-1][b] = 0;
                        }
                    }
                    maxArea = max(currArea, maxArea);
                }
            }
        }
        return maxArea;
    }
};
