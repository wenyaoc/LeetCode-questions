class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n, 0);
        if (s[0] != '0') dp[0] = 1; // n == 1
        if (n == 1) return dp[0];

        int num = 10*(s[0]-'0') + (s[1]- '0'); // n == 2
        if (num > 26 && s[1] == '0') return 0;

        if (num <= 26 && num > 10 && num != 20) dp[1] = 2;
        else dp[1] = dp[0];
        if (n == 2) return dp[1]; 

        for (int i = 2; i < n; i++) { // n > 2
            num = 10*(s[i-1]-'0') + (s[i]- '0');
            if (s[i] == '0') { 
                if (s[i-1] == '0' || num > 26) return 0;
                dp[i] = dp[i-2];
            } else if (num <= 26 && num > 10) dp[i] = dp[i-1] + dp[i-2];
            else dp[i] = dp[i-1];
        }
        return dp[n-1];
    }
};
