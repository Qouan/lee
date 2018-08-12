#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int min_steps=100;
  int times=0;
  vector<int>results;
void find(vector<int>& nums,int index){
  for(;index<nums.size();){
      for(int step=1;step<=nums[index];++step){
          index+=step;
          times++;
          if(index==nums.size()-1) {min_steps=times;
              results.push_back(times);}
          find(nums,index);
          index-=step;
          times--;
        }
      return;
    }
}
void jump(vector<int>& nums) {
        return find(nums,0);
    }
int main()
{
  vector<int> nums;
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(4);
  jump(nums);
  cout<<*min_element(results.begin(),results.end());
}ju
