class NumArray {
    vector<int> prefix={0};
public:
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            prefix.push_back(nums[i]+prefix[i]);
        }
    }
    
    int sumRange(int i, int j) {
        return prefix[j+1] - prefix[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
