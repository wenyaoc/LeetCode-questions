char * longestPalindrome(char * s){
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int start = 0;
    int currIndex = 0;

    while (s[currIndex]) {
        right = currIndex;
        left = right - 1;

        while (s[right] == s[currIndex]) right++;

        currIndex = right;

        while (left >= 0 && s[right] && s[right] == s[left]) {
            left--;
            right++;
        }

        if(right-left-1 > maxLength){
            start = left + 1;
            maxLength = right-left-1;
        }
    }

    char * ans = malloc((maxLength + 1) * sizeof(char));
    ans[maxLength] = '\0';
    for (int i = 0; i < maxLength; i++) {
        ans[i] = s[start + i];
    }
    return ans;
}
