class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n+1, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};


/*
class Solution {
public:
    bool isSquare(int n)
    {
        if(!(int(sqrt(n))-sqrt(n)))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int numSquares(int n) {
        while(!(n&3))
        {
            n=n>>2;
        }
        if((n&7)==7)
        {
            return 4;
        }
        if(isSquare(n))
        {
            return 1;
        }
        for(int i=1;i<sqrt(n);i++)
        {
            if(isSquare(n-i*i))
            {
                return 2;
            }
        }
        return 3;

    }
};
*/
