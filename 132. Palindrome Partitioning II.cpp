#include<iostream>
#include<unordered_map>
#include<limits.h>
using namespace std;
unordered_map<string,bool>mymap;
    int times=0;int mini=INT_MAX;
    void cut(string&s);
int minCut(string s)
{
	   int len=s.size();
	   for(int j=0;j<len;++j)
	   {
			  for(int i=0;i<=j;++i)
			  {
					 if(i==j){mymap[s.substr(i,1)]=true;continue;}
					 if(i+1==j)mymap[s.substr(i,2)]=(s[i]==s[j])?true:false;
					 else mymap[s.substr(i,j-i+1)]=(s[i]==s[j]&&mymap[s.substr(i+1,j-i-1)])?true:false;
			  }
	   }
	   cut(s);
	   return mini;
}

void cut(string&s)
{
	   if(mymap[s]){mini=min(mini,times);return;}
	   for(int i=s.size()-1;i>0;i--)
	   {
			  string left=s.substr(0,i);
			  if(mymap[left]==false)continue;
			  times++;
			  string right=s.substr(i);
			  if(mymap[right]==true){mini=min(mini,times);}
			  else cut(right);
			 times--;
	   }
	   return ;}

int main()
{
    string s="aaabaa";
    cout<<minCut(s);
}

