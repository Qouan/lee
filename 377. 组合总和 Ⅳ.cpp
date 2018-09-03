class Solution {
public:
   int combinationSum4(vector<int>& nums, int target)
{
    vector<int>distrib(target+1);
    distrib[0]=1;
    for(int i=0;i<=target;++i)
    {
        for(int j=0;j<nums.size();++j)
        {
            if(i-nums[j]>=0)
            {
                distrib[i]+=distrib[i-nums[j]];
            }
        }
    }
    return distrib[target];
}


};