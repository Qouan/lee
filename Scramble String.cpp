//87
/*
这道题定义了一种爬行字符串，就是说假如把一个字符串当做一个二叉树的根，然后它的非空子字符串是它的子节点，然后交换某个子字符串的两个子节点，重新爬行回去形成一个新的字符串，这个新字符串和原来的字符串互为爬行字符串。这道题可以用递归Recursion或是动态规划Dynamic Programming来做，我们先来看递归的解法，参见网友uniEagle的博客，简单的说，就是s1和s2是scramble的话，那么必然存在一个在s1上的长度l1，将s1分成s11和s12两段，同样有s21和s22.那么要么s11和s21是scramble的并且s12和s22是scramble的；要么s11和s22是scramble的并且s12和s21是scramble的。就拿题目中的例子 rgeat 和 great 来说，rgeat 可分成 rg 和 eat 两段， great 可分成 gr 和 eat 两段，rg 和 gr 是scrambled的， eat 和 eat 当然是scrambled。
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
#include<stack>
using namespace std;
bool isScramble(string s1, string s2)
{
	   if(s1==s2)return 1;
	   if(s1.size()!=s2.size())return 0;
	   string s1_cp=s1,s2_cp=s2;
	   sort(s1_cp.begin(),s1_cp.end());
	   sort(s2_cp.begin(),s2_cp.end());
	   if(s1_cp!=s2_cp)return 0;
	   for(int i=1;i<s1.size();++i)
	   {
			  string s11=s1.substr(0,i);
			  string s12=s1.substr(i);
			  string s21=s2.substr(0,i);
			  string s22=s2.substr(i);
			  if(isScramble(s11,s21)&&isScramble(s12,s22))return 1;
			  s21=s2.substr(s2.size()-i);
			  s22=s2.substr(0,s2.size()-i);
			   if(isScramble(s11,s21)&&isScramble(s12,s22))return 1;
	   }
	   return 0;
}
int main()
{
	   string s1="great";
	   string s2="rgeat";
	   cout<<isScramble(s1,s2);
}

