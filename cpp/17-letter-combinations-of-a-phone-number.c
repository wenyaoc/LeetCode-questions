class Solution {
public:
    map<char,string> mp={
            {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"}, 
            {'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if (digits == "") return res;
        string curr = "";
        dfs(digits, curr, res);
        return res;
    }
    void dfs (string digits, string curr, vector<string> &res) {
        if (!digits.size()) {
            res.push_back(curr);
        } else {
            char num = digits[0];
            string letter = mp[num];
            for (int i = 0; i < letter.size(); i++) {
                curr.push_back(letter[i]);
                dfs(digits.substr(1), curr, res);
                curr.pop_back();
            }
        }
    }
};
