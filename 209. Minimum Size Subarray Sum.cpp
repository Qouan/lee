class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int now=0;int right=0;
        int len=nums.size();
        while(now<s)
        {
            if(right==len)return 0;
            now+=nums[right];
            ++right;
        }
        int left=0;
        int res=right;
        --right;
        now-=nums[right];
        for(int i=right;i<len;++i)
        {
            now+=nums[i];
            while(now-nums[left]>=s)
            {
                now-=nums[left];
                ++left;
            }
            res=min(res,i-left+1);
        }
        return res;
    }
};
