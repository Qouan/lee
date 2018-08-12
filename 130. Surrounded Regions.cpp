//深搜,从边缘开始搜索
class Solution {
public:
    
void search(vector<vector<char>>&board,int i,int j)
{
	   if(board[i][j]=='X'||board[i][j]=='#')return ;
	   board[i][j]='#';
	   if(i+1<board.size())search(board,i+1,j);
	   if(i-1>=0)search(board,i-1,j);
	   if(j-1>=0)search(board,i,j-1);
	   if(j+1<board[0].size())search(board,i,j+1);
}
   void solve(vector<vector<char>>& board)
{
	   int m=board.size();
       if(m==0)return;
	   int n=board[0].size();
	   for(int i=0;i<m;++i)
	   {
			  for(int j=0;j<n;++j)
			  {
					 if((i==0||i==m-1)&&board[i][j]=='O')search(board,i,j);
					 if((j==0||j==n-1)&&board[i][j]=='O')search(board,i,j);
			  }
	   }
	   for(int i=0;i<m;++i)
	   {
	   for(int j=0;j<n;++j)
	   {
	   if(board[i][j]=='O')board[i][j]='X';
        if(board[i][j]=='#')board[i][j]='O';
	   }
	   }
}



};
