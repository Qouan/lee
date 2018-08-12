class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        if(len==0)return 0;
        if(len==1)return nums[0];
        int dp[len]={nums[0],max(nums[0],nums[1])};
        for(int i=2;i<len;++i)
        {
            dp[i]=max(dp[i-1],nums[i]+dp[i-2]);
        }
        return dp[len-1];
    }
};
