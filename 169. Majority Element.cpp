class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int res=-1;
	   for(auto num:nums)
	   {
			  if(count==0){res=num;}
			  if(num==res)++count;
			  else --count;
	   }return res;
    }
};
