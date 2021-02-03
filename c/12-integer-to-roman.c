//执行用时: 12 ms
//内存消耗: 6.9 MB


# define ROMAN_NUM 7
# define VALUE_NUM ROMAN_NUM*2-1

char * intToRoman(int num){
    int value[VALUE_NUM] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    char roman[ROMAN_NUM] = {'I','V','X','L','C','D','M'};
    char * ans = NULL;
    int i = VALUE_NUM-1;
    int j = 0;
    while (i >= 0) {
        if (num - value[i] >= 0) {
            int index = (i+1)/2;
            if (i%2 != 0) {
                ans = realloc(ans, (j+1)*sizeof(char));
                if (i%4 == 1) ans[j] = roman[index-1];
                else ans[j] = roman[index-2];
                j++;
            }
            ans = realloc(ans, (j+1)*sizeof(char));
            ans[j] = roman[index];
            num = num - value[i];
            j++; 
        } else i--;
    }
    ans = realloc(ans, (j+1)*sizeof(char));
    ans[j] = '\0';
    return ans;

}
