//取余数,余数可以等于26,所以要额外判断
class Solution {
public:
    string convertToTitle(int n) {
         string res="";
	   while(n>0)
	   {
			  int yushu=(n-1)%26+1;
			  res=string(1,'A'+yushu-1)+res;
			  n=(n-yushu)/26;
	   }
	   return res;}
};
