#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
using namespace std;
void sortColors(vector<int>& nums)
{
	   int a_count=0,b_count=0,c_count=0;
	   for(int i=0;i<nums.size();++i)
	   {
			  if(nums[i]==0)a_count++;
			  else if(nums[i]==1)b_count++;
			  else c_count++;
	   }
	   nums.clear();
	   for(int i=0;i<a_count;++i)nums.push_back(0);
	   for(int i=0;i<b_count;++i)nums.push_back(1);
	   for(int i=0;i<c_count;++i)nums.push_back(2);
}

int main()
{
	   vector<int> nums;
	   nums.push_back(2);
		nums.push_back(0);
		 nums.push_back(2);
		  nums.push_back(1);
		   nums.push_back(1);
			nums.push_back(0);
			sortColors(nums);
			for(int i=0;i<8;++i)cout<<nums[i];
			}

