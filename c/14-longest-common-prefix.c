//执行用时: 0 ms
//内存消耗: 5.7 MB

char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0, index = 0;
    int length = 0;
    char * ans = NULL;
    if (strsSize == 0) {
        ans = malloc(sizeof(char));
        ans[0] = 0;
        return ans;
    }
    while (strs[0][index] != 0) {
        char currCharacter = strs[0][index];
        i = 1;
        while (i < strsSize) {
            if (strs[i][index] == 0 || strs[i][index] != currCharacter) {
                ans = realloc(ans, (index+1)*sizeof(char));
                ans[index] = 0;
                return ans;
            }
            i++;
        }
        index ++;
        ans = realloc(ans, (index)*sizeof(char));
        ans[index-1] = currCharacter;
    }
    ans = realloc(ans, (index+1)*sizeof(char));
    ans[index] = 0;
    return ans;
}
