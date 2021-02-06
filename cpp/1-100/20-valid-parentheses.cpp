class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') brackets.push(')');
            else if (s[i] == '{') brackets.push('}');
            else if (s[i] == '[') brackets.push(']');
            else {
                if (brackets.empty()) return false;
                if (s[i] != brackets.top()) return false;
                brackets.pop();
            }
        }
        if (brackets.empty()) return true;
        return false;
    }
};
