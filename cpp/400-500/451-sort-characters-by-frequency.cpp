class Solution {
public:
    string frequencySort(string s) {
        unordered_map<int, int> counts;
        int max_count = 0;
        for (const int & letter : s) {
            max_count = max(max_count, ++counts[letter]);
        }
        vector<vector<int>> buckets(max_count + 1);

        for (const auto & p : counts) {
            buckets[p.second].push_back(p.first);
        }
        string ans;

        for (int i = max_count; i > 0; i--) {
            for (const int & letter : buckets[i]) {
                for (int j = 0; j < i; j++)
                    ans.push_back(letter);
            }
        }
        return ans;
    }
};
