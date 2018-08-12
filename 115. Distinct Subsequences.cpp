//动态规划 要求(0,i)转换成(0,j)的方法,可以根据前一状态推断
class Solution {
public:
    int numDistinct(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1<len2)return 0;
	   int dp[len1][len2]={};
	   if(s[0]==t[0])dp[0][0]=1;
	   for(int i=1;i<len1;++i)
	   {
			  if(s[i]==t[0])dp[i][0]=dp[i-1][0]+1;
			  else dp[i][0]=dp[i-1][0];
	   }
	   for(int i=1;i<len1;++i)
			  for(int j=1;j<len2;++j)
			  {
					 if(j>i)continue;
					 if(s[i]==t[j])dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
					 else dp[i][j]=dp[i-1][j];
			  }
        
		return dp[len1-1][len2-1];	  
    }
};
