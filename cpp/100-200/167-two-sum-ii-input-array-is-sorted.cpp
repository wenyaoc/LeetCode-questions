class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            int total = numbers[i] + numbers[j];
            if (total == target) break;
            else if (total > target) j--;
            else i++;
        }
        return vector<int>{i + 1, j + 1};
    }
};
