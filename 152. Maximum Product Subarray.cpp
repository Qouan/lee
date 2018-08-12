//https://blog.csdn.net/sjwl2012/article/details/54576777
/*我们会注意到，数组中数据可正可负。所以，有些棘手。

但是仔细分析。正数乘以正数为正数，负数乘以负数为正数。比如当前元素值为正数，则正数才会更大。即出现更大的值，如果出现负数，则乘以负数才会得到更大的值。 
所以我们需要记录两个值，一个是最大值，一个是最小值。初始情况，最大值，最小值均为第一个元素。然后向后遍历数组，分别和最大值和最小值相乘得到结果，然后最大值和两者乘积结果中的最大值对比更新。 
然后最小值和乘积结果中的最小值对比更新。
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
       if(nums.size()==1)return nums[0];
	int maxpro=nums[0];
	int minpro=nums[0];
	int res=nums[0];
	for(int i=1;i<nums.size();++i)
	{
		int t=maxpro*nums[i];
		int s=minpro*nums[i];
		maxpro=max(max(t,s),nums[i]);
		minpro=min(min(t,s),nums[i]);
		res=max(maxpro,res);
	}return res;}
};
