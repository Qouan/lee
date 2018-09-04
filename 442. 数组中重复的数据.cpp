class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int>ret;
   int len= static_cast<int>(nums.size());
//将目标数据变成负数,既保留了原有数据又保留了访问记录
    for(int i=0;i<len;++i)
    {
        int idx=abs(nums[i])-1;
        if(nums[idx]<0)ret.push_back(idx+1);
        nums[idx]*=-1;
    }
    return ret;
    }
};