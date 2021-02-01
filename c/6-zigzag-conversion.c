/*
执行用时：8 ms, 在所有 C 提交中击败了81.48%的用户
内存消耗：6.4 MB, 在所有 C 提交中击败了67.48%的用户
*/

#define MAX(a,b) (((a)>(b))?(a):(b))

char * convert(char * s, int numRows){
    int period = numRows + MAX(0, numRows-2);
    int gap = 0;
    int length = strlen(s);
    int currRow = 1;
    int currStringIndex = 0;
    int currAnsIndex = 0;
    char * ans = malloc((length + 1) * sizeof(char));
    ans[length] = '\0';
    while (gap <= period) {
        currStringIndex = currRow - 1;
        while (currStringIndex < length) {
            if (period - gap != 0) {
                ans[currAnsIndex] = s[currStringIndex];
                currAnsIndex ++;
                currStringIndex += (period - gap);
            }
            if (currStringIndex >= length) break;
            else if (gap != 0) {
                ans[currAnsIndex] = s[currStringIndex];
                currAnsIndex ++;
                currStringIndex += gap;
            }
        }
        gap += 2;
        currRow++;
    }
    return ans;
}
