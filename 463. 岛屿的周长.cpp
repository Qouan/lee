class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size();
    if(m==0)return 0;
    int n=grid[0].size();
    int sum=0;
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {

            if(grid[i][j]==1)
            {
                sum+=4;
                if(i-1>=0&&grid[i-1][j]==1)
                    sum-=1;
                if(i+1<m&&grid[i+1][j]==1)
                    sum-=1;
                if(j-1>=0&&grid[i][j-1]==1)
                    sum-=1;
                if(j+1<n&&grid[i][j+1]==1)
                    sum-=1;
            }
        }
    }
    return sum;}
};