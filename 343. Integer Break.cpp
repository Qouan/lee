class Solution {
public:
int integerBreak(int n){
    if(n==0||n==1)return 1;
    if(n<=4){
        if(n%2==0)return n*n/4;
        if(n%2==1)return n/2*(n/2+1);
    }
    vector<int>dp(n+1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=i;++j){
            if(i<=4){
                dp[i]=i;
            }else
            dp[i]=max(dp[i],dp[i-j]*j);
        }
    }
    return dp[n];}
};