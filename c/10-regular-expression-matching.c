//执行用时: 36 ms
//内存消耗: 5.4 MB


bool all_equal(char *s) { //判断字符串内字符是否全部相等
    if (s[0] == 0) return true;
    int i = 0;
    while(s[i+1] != 0) {
        if (s[i] == s[i+1]) i++;
        else return false;
    }
    return true;
}

bool isMatch(char * s, char * p){
    int i = 0, j = 0;
    if (s[0] == 0 && p[0] == 0) return true; // 都为空，直接返回

    while (1) {
        if (p[j] == 0 ) { // p结束
            if (s[i] != 0) return false;
            else return true;
        }
        else if (p[j] == '*') {
            if (s[i] == s[i-1] || s[i] == 0 || p[j-1] == '.' || s[i-1] == p[j-1]) {
               if (p[j+1] == 0 && all_equal(s+i-1)) return true;
                bool find_match = false;
                int addIndex = 0;
                while (*(s+i+addIndex-1) != 0) {
                    if(isMatch(s+i+addIndex-1, p+j+1)) return true;
                    if (s[i+addIndex-1] != s[i-1] && p[j-1] != '.' && s[i] != 0) return false;
                    addIndex++;
                }
                return (isMatch(s+i+addIndex-1, p+j+1)); 
            } else j++;
        } else if (p[j] == s[i] || (p[j] == '.' && s[i] != 0) ) {
            i++;
            j++;
        } else if (p[j+1] != 0 && p[j+1] == '*') { //当前*字符匹配零个元素
            j += 2;
        } else return false;
    }
    if (s[i] == 0 && p[j] != 0) { // p未结束，判断剩余字符是否可以消掉
        bool odd = true;
        bool even = true;
        int addj = 1;
        while (p[j + addj] != 0) {
            if ((addj) % 2 == 0) {
                if (p[j + addj] != '*') odd = false;
            } else {
                if (p[j + addj] != '*') even = false;
            }
            addj++;
        }
        if (p[j+addj-1] != '*') return false;

        if (odd || even) return true;
        else return false;
    }
    if (s[i] == 0 && i != 0) return true;
    return false;
}
