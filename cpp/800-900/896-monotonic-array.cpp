class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool dec = true;
        bool inc = true;
        int n = A.size();
        if (n <= 1) return true;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) dec = false;
            if (A[i] < A[i-1]) inc = false;
        }
        return dec||inc;
    }
};
