class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if (n < 2) return 0;
        int res = 0; // the returned answer
        int numCons = 2; // continous # in the arithmetic array;
        int diff = A[1] - A[0];
        int factorial = 1;


        for (int i = 2; i < n; i++) {
            int currDiff = A[i] - A[i-1];
            if (currDiff == diff) {
                numCons++;
                if (numCons >= 3) res += (factorial * (numCons-2));
            } else {
                numCons = 2;
                diff = currDiff;
            }
        }

        return res;
    }
};
