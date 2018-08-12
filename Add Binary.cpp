#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
string addBinary(string a, string b) {
	  if(a.size()>b.size())
	  return addBinary(b,a);
	  int carry=0;
	  int dis=b.size()-a.size();
	  for(int i=a.size()-1;i>=0;i--)
	  {
			  int temp=a[i]+b[i+dis]-2*'0'+carry;
			  b[i+dis]=temp%2+'0';
			  carry=temp/2;
	  }
	  if(carry==0)return b;
	  if(dis==0) {b=string(1,carry+'0')+b;return b;}
	  for(int j=dis-1;j>=0;j--)
	  {
			  int temp=b[j]-'0'+carry;
			  b[j]=temp%2+'0';
			  carry=temp/2;
			  if(!carry)break;
	  }
	  if(carry!=0)b=string(1,carry+'0')+b;
	  return b;
}

int main()
{
	   string a="101111",b="10";
	   cout<<addBinary(a,b);
}
