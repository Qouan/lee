class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=int(nums.size());
    if(len==0)
        return {};
    sort(nums.begin(),nums.end());
    vector<vector<int> >dp(len,vector<int>{1,-1});//[0]储存长度，[1]储存上一级下标
    for(int i=1;i<len;++i){
        for(int j=0;j<i;++j){
            if(nums[i]%nums[j]==0&&dp[j][0]+1>dp[i][0]){
                dp[i][0]=dp[j][0]+1;
                dp[i][1]=j;
            }
        }
    }
    int index=-1,maxsize=-1;
    for(int i=0;i<len;++i){
        if(dp[i][0]>maxsize){
            maxsize=dp[i][0];
            index=i;
        }
    }
    vector<int>res;
    while(dp[index][1]!=-1){
        res.push_back(nums[index]);
        index=dp[index][1];
    }res.push_back(nums[index]);
    reverse(res.begin(),res.end());
    return res;
    }
};