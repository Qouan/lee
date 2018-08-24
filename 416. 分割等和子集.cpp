class Solution {
public:bool canPartition(vector<int>& nums){
  int sum=accumulate(nums.begin(),nums.end(),0);
    if(sum%2==1)return false;
    vector<vector<int> >mat(nums.size(),vector<int>(static_cast<unsigned int>(sum/2+1)));
    int target=sum/2;
    for(int i=0;i<nums.size();++i)
    {
        for(int j=0;j<=target;++j)
        {
            if(i==0)
            {
                mat[i][j]=nums[i]==j?1:0;
                //continue;
            }
            else if(mat[i-1][j]==1||(j-nums[i]>0&&mat[i-1][j-nums[i]]==1)) {
                mat[i][j] = 1;
            }
            
            if(mat[i][target]==1)return true;
        }
    }
    return false;}
};