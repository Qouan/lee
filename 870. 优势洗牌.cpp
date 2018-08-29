public:
    int mid_find(vector<int>&a,int target)
{
    int l=0,r=a.size()-1;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(a[mid]==target)return mid+1;
        if(a[mid]<target)l=mid+1;
        else r=mid-1;
    }
    return l;
}
vector<int> advantageCount(vector<int>& A, vector<int>& B)
{
    sort(A.begin(),A.end());
    vector<int>visit(A.size());
    vector<int>tmp(A.size());
    for(int i=0;i<A.size();++i)
    {
        int re=mid_find(A,B[i]);
         while(re<A.size()&&(visit[re]==1||A[re]<=B[i]))++re;
        if(re>=A.size())
        {
            int j=0;
            while(visit[j]==1)++j;
            visit[j]=1;
            tmp[i]=A[j];
        }
        else
        {
            tmp[i]=A[re];
            visit[re]=1;
        }
    }
    return tmp;
}
};
