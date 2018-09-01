class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     int len=nums.size();
    int min1=INT_MAX,min2=INT_MAX;
    for(int i=0;i<len;++i)
    {
        if(nums[i]<min1)
            min1=nums[i];
        if(nums[i]<min2&&nums[i]>min1)
            min2=nums[i];
        if(nums[i]>min2)return true;
    }
    return false;
    }
};
