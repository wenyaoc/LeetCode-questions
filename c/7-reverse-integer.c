/*
执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗：5.3 MB, 在所有 C 提交中击败了91.44%的用户
*/
int reverse(int x){
    int ans = 0;
    int is_negative = 0;
    if (x < 0) {
        if (x < -INT_MAX) return 0;
        x = -x;
        is_negative = 1;
    }
    while (x > 0) {
        if (ans > INT_MAX/10) return 0;
        ans = ans * 10;
        if (ans > INT_MAX -  x%10) return 0;
        ans = ans + x%10;
        x = x/10;
    }
    if (is_negative) ans = -ans;
    return ans;

}
