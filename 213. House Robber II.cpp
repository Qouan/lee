class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty())return 0;
         int len=nums.size()-1;
        if(len==0)return nums[0];
	   int dp[len];
	   for(int i=0;i<len;++i)
	   {
			  if(i==0){dp[i]=nums[i];continue;}
			  if(i==1){dp[i]=max(nums[i],nums[i-1]);continue;}
			  dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
	   }int mx=dp[len-1];
	   nums.erase(nums.begin());
	    for(int i=0;i<len;++i)
	   {
			  if(i==0){dp[i]=nums[i];continue;}
			  if(i==1){dp[i]=max(nums[i],nums[i-1]);continue;}
			  dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
	   }return max(mx,dp[len-1]);
    }
};
