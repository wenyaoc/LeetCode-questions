bool compare(vector<int> a,vector<int> b)
{
    if(a[0] == b[0])
        return a[1]>b[1];
    return a[0]<b[0];
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int res=1,size=envelopes.size();
        vector<int>dp(size,1);
        if(size==0) return 0;
        sort(envelopes.begin(),envelopes.end()); 
        for(int i=1;i<size;i++)
        {
            int temp=0;
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1]){temp=max(temp,dp[j]);}
            }
            dp[i]=temp+1;res=max(res,dp[i]);
        }
        return res;

    }
};
