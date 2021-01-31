int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxLen = 0;
    char ascii_map[256] = {0};
    ascii_map[(int)s[start]] = 1;

    while (s[end] != 0) {
        maxLen = maxLen>(end - start + 1) ? maxLen : (end - start + 1);
        end++;
        while (ascii_map[(int)s[end]] != 0) {
            ascii_map[(int)s[start]] = 0;
            start++;
        }
        ascii_map[(int)s[end]] = 1;
    }
    return maxLen;
}   
