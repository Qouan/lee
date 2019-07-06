class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int len=int(nums.size());
    if(len==0)
        return {};
    sort(nums.begin(),nums.end());
    vector<int> dp(len);
    vector<int>divi(len);
    for(int index_dp=0;index_dp<len;++index_dp){
        int lastMaxLen=0;
        for(int j=index_dp-1;j>=0;--j){
            if(nums[index_dp]%nums[j]==0&&dp[j]>lastMaxLen) {
                lastMaxLen=dp[j];
                divi[index_dp]=j;
            }
        }
        dp[index_dp]=lastMaxLen+1;
    }
    int maxIndex=distance(dp.begin(),find(dp.begin(),dp.end(),*max_element(dp.begin(),dp.end())));
    vector<int>res;
    int next=nums[maxIndex];
    int times=dp[maxIndex];
    while(times--){
        res.push_back(next);
        maxIndex=divi[maxIndex];
        next=nums[maxIndex];
    }
    return res;
    }
};