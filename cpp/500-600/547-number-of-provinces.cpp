class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;
                stack<int> city;
                city.push(i);
                while(!city.empty()) {
                    int currCity = city.top();
                    city.pop();
                    visited[currCity] = true;
                    for (int j = 0; j < n; j++) {
                        if (isConnected[currCity][j] && !visited[j]) {
                            city.push(j);
                        }    
                    }
                }
            }
        }
        return count;
    }
};
