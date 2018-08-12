class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int>myset;
	int len;
	int mx=INT_MIN;

	for(int num:nums)myset.insert(num);

	for(int i=0;i<nums.size();++i)
	{
		len=0;
		if(myset.find(nums[i])!=myset.end())
		{
			++len;
			myset.erase(nums[i]);
			for(int j=nums[i]+1;;++j)
			{
				if(myset.find(j)!=myset.end()){
				++len;
				myset.erase(j);}
				else break;
			}
			for(int j=nums[i]-1;;--j)
			{
				if(myset.find(j)!=myset.end()){
				myset.erase(j);
				++len;}
				else break;
			}
		}
		mx=max(mx,len);
	}
	return max(mx,0);  
    }
};
