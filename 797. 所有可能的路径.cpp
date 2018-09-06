class Solution {
public:
  vector<vector<int> >ret;

void find(vector<vector<int>>& graph,vector<int>&path,int start)
{
    for(int i=0;i<graph[start].size();++i)
    {
        path.push_back(graph[start][i]);
        if(graph[start][i]==graph.size()-1)
        {
            ret.push_back(path);
            path.pop_back();
            continue;
        }
        find(graph,path,graph[start][i]);
        path.pop_back();
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
{
    vector<int>path(1,0);
    find(graph,path,0);
    return ret;
}
};