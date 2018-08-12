class Solution {
public:
    int findPeakElement(vector<int>& nums)
{
        if(nums.size()==1)return 0;
        if(nums[0]>nums[1])return 0;
        int len=nums.size()-1;
        if(nums[len]>nums[len-1])return len;
	   return peak(nums,0,nums.size()-1);
}
int peak(vector<int>&nums,int l,int r)
{
	   if(r-l<2)return -1;
	   int mid=(l+r)/2;
	   if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
	   return mid;
	   return max(peak(nums,l,mid),peak(nums,mid,r));
}
};
