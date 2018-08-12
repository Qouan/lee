  int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp,0,m*n*sizeof(int));
      
        for(int col=n-1;col>=0;--col)
          {
              for(int row=m-1;row>=0;--row)
                {
                      if(row==m-1||col==n-1)  {dp[row][col]=1;continue;}
                      dp[row][col]=dp[row+1][col]+dp[row][col+1];
                }
          }
        return dp[0][0];
}
