int myAtoi(char * s){
    int i = 0;
    char is_negative = 0;
    long ans;
    while (s[i] < '0' || s[i] > '9') {
        if (s[i] == ' ' || ((s[i] == '-' || s[i] == '+') && (s[i+1] >= '0' && s[i+1] <= '9'))) i++;
        else return 0;
    }
    if (i != 0 && s[i-1] == '-') is_negative = 1;
    while (s[i] != 0 && s[i] >= '0' && s[i] <= '9') {
        
        if (ans > INT_MAX/10 + 1) {
            ans = -(long)INT_MIN;
            break;
        } 
        
        ans = ans * 10;
        
        if (ans + (s[i] - '0')  > -(long)INT_MIN) {
            ans = -(long)INT_MIN;
            break;
        } 
        ans = ans + (s[i] - '0');
        i++;
    }
    if (is_negative == 1) {
        ans = -ans;
        if (ans < INT_MIN) ans = INT_MIN;
    } else if (ans > INT_MAX) {
        ans = INT_MAX;
    }
    return ans;
}
