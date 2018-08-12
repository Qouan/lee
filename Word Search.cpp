#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
#include<utility>
#include<stack>
using namespace std;
 vector<pair<int,int> > find_neibor(vector<vector<char> >& board,int i,int j,char b)
{
	   vector<pair<int,int> >res;
	 //try{if(board[i-1][j-1]==b)res.push_back(make_pair(i-1,j-1));}catch(...){}
	 try
	 {
	 if(board.at(i-1).at(j)==b)res.push_back(make_pair(i-1,j));
	 }
	 catch(...){}
	// try{if(board[i-1][j+1]==b)res.push_back(make_pair(i-1,j+1));}catch(...){}
	 try{if(board.at(i).at(j-1)==b)res.push_back(make_pair(i,j-1));}catch(...){}
	 try{if(board.at(i).at(j+1)==b)res.push_back(make_pair(i,j+1));}catch(...){}
	 //try{if(board[i+1][j-1]==b)res.push_back(make_pair(i+1,j-1));}catch(...){}
	 try{if(board.at(i+1).at(j)==b)res.push_back(make_pair(i+1,j));}catch(...){}
	// try{if(board[i+1][j+1]==b)res.push_back(make_pair(i+1,j+1));}catch(...){}
	 return res;
}

bool dfs(vector<vector<char> > &board,string &word,int i,int j,int pos)
{
	   if(pos==word.size()-1)return 1;
		vector<pair<int,int> >path= find_neibor(board,i,j,word[pos+1]);
		for(int k=0;k<path.size();++k)
		{
		//cout<<path.size();
			  if(board[i][j]=='?')continue;
			  char record=board[i][j];
			  board[i][j]='?';
			   if(dfs(board,word,path[k].first,path[k].second,pos+1))
					 return 1;
			   board[i][j]=record;
		}return 0;
}

bool exist(vector<vector<char> >&board, string word)
{
	   if(board.empty()||word.empty())return 0;
	   int m=board.size(),n=board[0].size();
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
			if(board[i][j]==word[0])
		if(dfs(board,word,i,j,0))return 1;
	return 0;
}

int main()
{
	   vector<vector<char> >board;
//	   char a[]={'C','A','A'};
//vector<char>p1(a,a+3);
//   board.push_back(p1);;
//	   char b[]={'A','A','A'};
//	   vector<char>p2(b,b+3);
//		 board.push_back(p2);
//	   char c[]={'B','C','D'};
//  vector<char>p3(c,c+3);
//		 board.push_back(p3);
//	 string s="AAB";
//		// cout<<board[2][3];
vector<char>a;
a.push_back('b');
board.push_back(a);
vector<char>a1;
a1.push_back('a');
board.push_back(a1);
vector<char>a2;
a2.push_back('b');
board.push_back(a2);
vector<char>a3;
a3.push_back('b');
board.push_back(a3);
vector<char>a4;
a4.push_back('a');
board.push_back(a4);
		 cout<<exist(board,"baa");
}

