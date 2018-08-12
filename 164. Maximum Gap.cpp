class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len=nums.size();
        if(len<2)return 0;
        sort(nums.begin(),nums.end());
        int diff=nums[1]-nums[0];
        
        for(int i=2;i<len;++i)
        {
            diff=max(diff,nums[i]-nums[i-1]);
        }return diff;
    }
};
