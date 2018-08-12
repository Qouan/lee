#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<utility>
using namespace std;
//Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.

//You have the following 3 operations permitted on a word:

//Insert a character
//Delete a character
//Replace a character
//Example 1:

//Input: word1 = "horse", word2 = "ros"
//Output: 3
//Explanation:
//horse -> rorse (replace 'h' with 'r')
//rorse -> rose (remove 'r')
//rose -> ros (remove 'e')
//Example 2:

//Input: word1 = "intention", word2 = "execution"
//Output: 5
//Explanation:
//intention -> inention (remove 't')
//inention -> enention (replace 'i' with 'e')
//enention -> exention (replace 'n' with 'x')
//exention -> exection (replace 'n' with 'c')
//exection -> execution (insert 'u')


//dp[i][j] means the least steps to change from word 1..i to word 1..j
		//when dealing with dp[i][j], of course dp[i-1][j], dp[i-1][j-1], etc. is done
		//When word1[i]=word2[j], we can have dp[i][j]=dp[i-1][j-1]
		//When word1[i]!=word2[j], we can remove this word dp[i][j]=dp[i-1][j]+1
		//                                or add a word dp[i][j]=dp[i][j-1]+1
		//                                or replace the word dp[i][j]=dp[i-1][j-1]+1
		//border: dp[0][j]=j
		//        dp[i][0]=i
		//        dp[0][0]=0
int minDistance(string word1, string word2) {
	   int len_word1=word1.size();
	   int len_word2=word2.size();
	   int dp[len_word1+1][len_word2+1];
	   memset(dp,0,len_word1*len_word2*sizeof(int));
	   word1=" "+word1;
	   word2=" "+word2;
	   for(int i=0;i<=len_word1;++i)dp[i][0]=i;
	   for(int i=0;i<=len_word2;++i)dp[0][i]=i;
	   for(int i=1;i<=len_word1;++i)
			  for(int j=1;j<=len_word2;++j)
			  {
					 dp[i][j]=min(dp[i-1][j],dp[i][j-1])+1;
					 if(word1[i]==word2[j])dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
					 else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
			  }
	  return dp[len_word1][len_word2];

	}
	int main()
	{
	   cout<<minDistance("intention","execution");
	}



















