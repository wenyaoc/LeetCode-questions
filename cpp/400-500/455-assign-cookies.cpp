class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        int chindSize = g.size();
        int cookieSize = s.size();
        int res = 0;
        while (child < chindSize && cookie < cookieSize) {
            if (g[child] <= s[cookie]) {
                child++;
                cookie++;
                res++;
            } else cookie++;
        }
        return res;
    }
};
