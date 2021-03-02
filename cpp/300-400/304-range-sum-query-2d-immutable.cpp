class NumMatrix {
public:
    vector<vector<int>> sum;
    NumMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = 0;
        if (row > 0) col = matrix[0].size();
        sum = vector<vector<int>>(row,vector<int>(col,0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0) {
                    sum[i][j] = matrix[i][j];
                } else if (i == 0) {
                    sum[i][j] = sum[i][j-1] + matrix[i][j];
                } else if (j == 0) {
                    sum[i][j] = sum[i-1][j] + matrix[i][j];
                } else {
                    sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = sum[row2][col2];
        if (row1 > 0) res -= sum[row1-1][col2];
        if (col1 > 0) res-= sum[row2][col1-1];
        if (row1 > 0 && col1 > 0) res += sum[row1-1][col1-1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
