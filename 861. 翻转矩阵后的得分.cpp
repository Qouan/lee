#include <iostream>
#include <vector>
#include <algorithm>
//#include<string.h>
using namespace std;
int matrixScore(vector<vector<int>>& A)
{
    int m=A.size();
    if(m==0)return 0;
    int n=A[0].size();

    //按行翻转,翻转首数字为0的行
    for(int i=0;i<m;++i)
    {
        if(A[i][0]==0)
        {
            for(int j=0;j<n;++j)
            {
                A[i][j]=1-A[i][j];
            }
        }
    }

    //按列翻转,翻转0比1多的列
    for(int j=1;j<n;++j)
    {
        int count=0;
        for(int i=0;i<m;++i)
            if(A[i][j]==0)
                ++count;
        if(count>m-count)
        {
            for(int i=0;i<m;++i)
                A[i][j]=1-A[i][j];
        }
    }

    //求和
    int sum=0;
    for(int i=0;i<m;++i)
    {
        int row=0;
        for(int j=0;j<n;++j)
            row=row*2+A[i][j];
        sum+=row;
    }
    return sum;
}
