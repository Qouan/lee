class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
     if(nums.size()<=1)return nums.size();
    while (nums.size()>1&&nums[0]==nums[1]){
        nums.erase(nums.begin());
    }
    if(nums.size()<=1)return nums.size();
    int flag=nums[0]<nums[1]?1:-1;
    int res=1;
    for(int i=1;i<nums.size();++i){
        int j=i+1;
        while(j<nums.size()&&(nums[j]-nums[j-1])*flag>=0){
            ++j;
        }
        i=j-1;
        flag*=-1;
        ++res;
        if(j==nums.size())break;
    }
    return res;
    }
};