class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
         vector<unsigned int>df(target+1,0);
        sort(nums.begin(),nums.end());
        df[0]=1;
    for(int i=1;i<=target;++i){
        for(int n:nums){
            if(i-n>=0)
            {
                df[i]+=df[i-n];
            }
            else{
                break;
            }
        }
    }
    return df[target];
    }
};