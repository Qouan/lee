//85
/*
cur_left和cur_right均由当前行的值来确定。如果当前值为'1'，则cur_left和cur_right均不变；如果当前值为'0'，则cur_left值为当前元素右侧，cur_right值为当前元素位置。（左闭右开） 
left[i][j]定义为在第i行第j列处，可以延伸到最左边元素的下标。 
right[i][j]定义为在第i行第j列处，可以延伸到最右边元素的下标+1。 
核心思路是从第一行开始一行一行地处理，使[i, j]处最大子矩阵的面积是(right(i, j)-left(i, j))*height(i, j)。其中height统计当前位置及往上'1'的数量；left和right是高度是当前点的height值的左右边界，即是以当前点为中心，以height为高度向两边扩散的左右边界。
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        	   if(matrix.empty())return 0;
	   int m=matrix.size(),n=matrix[0].size();
	   int *l= new int[n];
	   int*r= new int[n];
	   int*h=new int[n];
	   int max_size=0;
	   for(int i=0;i<n;++i)
	   {
			  l[i]=0;
			  r[i]=n;
			  h[i]=0;
	   }
	   for(int i=0;i<m;++i)
	   {
			  int c_l=0,c_r=n;
			  for(int j=0;j<n;++j)
			  {
					 if(matrix[i][j]=='1')h[j]+=1;
					 else							  h[j]=0;
                  cout<<h[j]<<" ";
			  }cout<<endl;
			  for(int j=0;j<n;++j)
			  {
					  if(matrix[i][j]=='1')l[j]=max(l[j],c_l);
					  else{
							l[j]=0;
							c_l=j+1;
					  }
			  }
			  for(int j=n-1;j>=0;--j)
			  {
					  if(matrix[i][j]=='1')r[j]=min(r[j],c_r);
					  else{
							r[j]=n;
							c_r=j;
					  }
			  }
			   for(int j = 0; j < n; j++)
			   {
					 max_size=max(max_size,(r[j]-l[j])*h[j]);
			   }
	   }
        delete []l;
            delete[]r;
        delete []h;
	   return max_size;
    }
};
