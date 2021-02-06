/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char curr[5] = {0};
int currSize = 0;
int currNumDigits = 0;

void dfs(char * digits, char ** ans, int totalSize) {
    int num = digits[0] - '2';
    num *= 3;
    if (digits[0] >= '8') num++;
    char letter[4];
    int letterTotal = 3;
    letter[0] = 'a' + num;
    letter[1] = 'b' + num;
    letter[2] = 'c' + num;
    if (letter[0] == 'p'|| letter[0] == 'w') { // 4 characters for 7 & 9
        letterTotal = 4;
        letter[3] = 'd' + num;
    }
    for (int i = 0; i < letterTotal; i++) {
        curr[currSize] = letter[i];
        currSize++;
        if (currSize == totalSize) {
            for(int j = 0; j < totalSize; j++) {
                ans[currNumDigits][j] = curr[j];
            } 
            ans[currNumDigits][totalSize] = 0;
            currNumDigits++;
        } else dfs(digits+1, ans, totalSize);
        currSize--;
    }
}



char ** letterCombinations(char * digits, int* returnSize){
    int digitsSize = strlen(digits);
    (*returnSize) = 0;
    if (digits[0] == 0) return NULL;
    int mul = 1;
    for(int i = 0; i < digitsSize; i++) {
        
        if (digits[i] == '7' || digits[i] == '9') mul = mul * 4;
        else mul = mul * 3;
        (*returnSize) = mul;
    }
    char ** ans = calloc((*returnSize) , sizeof (char *));
    for(int i = 0; i < (*returnSize); i++) {
        ans[i] = malloc((digitsSize+1)* sizeof(char));
        ans[i][digitsSize] = '\0';
    }
    currSize = 0;
    currNumDigits = 0;
    curr[0] = '\0';
    dfs(digits, ans, digitsSize);
    return ans;
}
