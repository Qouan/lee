#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
using namespace std;
  bool is_avaliable(char a,char b)
{
	   if(a>'2')return 0;
	   if(a=='1')return 1;
	   if(b<='6')return 1;
	   return 0;
}

int numDecodings(string s)
{
	   s+="?";
	   int dp[s.size()]={};
	   dp[s.size()-1]=1;
		int size=s.size()-1;
	   for(int i=size-1;i>=0;--i)
	   {
			  char a=s[i];
			  if(s[i]=='0')continue;
			  if(i==size-1){dp[i]=1;continue;}
			  if(s[i+1]==0)
			  {
					 if(s[i]>'2')return 0;
					 dp[i]=dp[i+2];
			}
			  else{
			  int a=is_avaliable(s[i],s[i+1])?dp[i+2]:0;
			  dp[i]=dp[i+1]+a;}
	   }
	   return dp[0];
}
int main()
{
	   string s="17";
	   cout<<numDecodings(s);
}

