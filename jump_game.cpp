#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
bool reach(int*dp,int index,int num,int len)
{
      for(int i=0;i<=num;++i)
        {
            if(index+i==len) break;
            if(dp[index+i]==1) return 1;
        }
      return 0;
}
    bool canJump(vector<int>& nus)
    {
        int len=nus.size();
        int dp[len];
       memset(dp,0,len*sizeof(int));
       dp[len-1]=1;
        for(int i=nus.size()-1;i>=0;--i)
          {
               if(reach(dp,i,nus[i],len)) dp[i]=1;
          }
          return dp[0]==1;
    }

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(0);
//    nums.push_back(1);
//    nums.push_back(0);
//    nums.push_back(4);
        int c=nums.size();
   int  a=canJump(nums);
    cout<<a;
}
