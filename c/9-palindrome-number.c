bool isPalindrome(int x){
    if (x < 0) return false;
    else if (x == 0) return true;
    
    long f=0;
    int temp=x;
    for ( ; x; f = f * 10 + x % 10, x /= 10);
    if (temp == f) return true;
    else return false;
}
