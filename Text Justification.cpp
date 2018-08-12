#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
void add_space(vector<string>&res,int maxwidth)
{
	   for(int i=0;i<res.size()-1;++i)
	   {	  int count=0;
			  int to_be_add=maxwidth-res[i].size();
			  if(to_be_add==0)continue;
			  int pos;
			  while((pos=res[i].find_first_of(' '))!=string::npos){res[i].replace(pos,1,"^");count++;}
			  if(!count){res[i].append(string(to_be_add,' '));continue;}
			  int a=to_be_add/count,b=to_be_add%count;
			  //cout<<a<<b<<endl;
			 // cout<<res[1]<<endl;
			  for(int j=0;j<count;j++)
			  {
					 int n=a+(j<b?1:0);
					 res[i].replace(res[i].find_first_of('^'),1,string(n+1,' '));
			  }
	   }int len=res.size();
	   res[len-1].append(string(maxwidth-res[len-1].size(),' '));
}

 vector<string> fullJustify(vector<string>& words, int maxWidth)
 {
	   vector<string>res;
	   string stockpile="";
	   for(int pos=0;pos<words.size();)
	   {
			  if(stockpile.empty()){stockpile+=words[pos];pos++;continue;}
			  if(stockpile.size()+words[pos].size()<maxWidth){stockpile+=" "+words[pos];pos++;}
			  else {res.push_back(stockpile);stockpile.clear();}
	   }if(!stockpile.empty())res.push_back(stockpile);
	   add_space(res,maxWidth);
	   return res;
 }
 int main()
 {
	   string s[]={"Science","is","what","we","understand","well","enough","to","explain",
		 "to","a","computer.","Art","is","everything","else","we","do"};
	   vector<string>words(s,s+18);
	   //cout<<words[6];
	   vector<string>res;
	   res=fullJustify(words,20);// res[1].append(2,' ');
	   for(int i=0;i<res.size();++i)cout<<res[i]<<endl;

	   cout<<res[2].size();
 }


