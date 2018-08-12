#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int min(int a,int b)
{
	   return a<b?a:b;
}

int minPathSum(vector<vector<int> >& grid)
{
	   int m=grid.size(),n=grid[0].size();
	   for(int col=n-1;col>=0;--col)
	   {
			  for(int  row=m-1;row>=0;--row)
			  {
					 if(row==m-1&&col==n-1)continue;
					 if(col==n-1){grid[row][col]+=grid[row+1][col];continue;}
					 if(row==m-1){grid[row][col]+=grid[row][col+1];continue;}
					 grid[row][col]+=min(grid[row+1][col],grid[row][col+1]);
			  }
		}
		return grid[0][0];
}

int main()
{
			  vector<int>a;
			  vector<vector<int> >v;
			  a.push_back(1);
			  a.push_back(3);
			  a.push_back(1);
			  v.push_back(a);
			  a.clear();
			  a.push_back(1);
			  a.push_back(5);
			  a.push_back(1);
			  v.push_back(a);
			  a.clear();
			  a.push_back(4);
			  a.push_back(2);
			  a.push_back(1);
			  v.push_back(a);
			  a.clear();
			   int re=minPathSum(v);
			   cout<<re;
}
