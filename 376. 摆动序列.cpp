class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
    int len=nums.size();
    if(len==0)
        return 0;
    int flag=0;
    vector<int>dp(len);dp[0]=1;
    for(int i=1;i<len;++i)
    {
        if(flag==0)
        {
            if(nums[i]==nums[i-1])
                dp[i]=dp[i-1];
            else
            {
                flag=nums[i]>nums[i-1]?1:-1;
                --i;
            }
            continue;
        }
         if((nums[i]-nums[i-1])*flag>0) {
             dp[i] = dp[i - 1] + 1;
             flag *= -1;
         }
        else dp[i]=dp[i-1];
        //cout<<dp[i]<<" ";
    }
    return dp[len-1];}
};
