//二分图  染色法
class Solution {
public:
   bool dfs(vector<vector<int> >&link,vector<int>&color,int pos,int C)
{
    if(color[pos]!=-1)
    {
        return color[pos]==C;
    }
    color[pos]=C;
    for(auto next:link[pos])
    {
        if(!dfs(link,color,next,1-C))return false;
    }
    return true;
}
bool possibleBipartition(int N, vector<vector<int>>& dislikes)
{
    vector<vector<int> >link(N+1);
    for(auto&ds:dislikes)
    {
        link[ds[0]].push_back(ds[1]);
        link[ds[1]].push_back(ds[0]);
    }vector<int>color(N+1,-1);
    for(int i=1;i<=N;++i)
    {
        if(color[i]==-1&&!dfs(link,color,i,1))return false;
    }
    return true;
}
};
