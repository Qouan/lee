class Solution {
public:

    
vector<vector<int>> updateMatrix(vector<vector<int>>& matrix)
{
       vector<vector<int> >ans=matrix;
        if(!ans.size() || !ans[0].size()) return ans;
        int rows=ans.size(),cols=ans[0].size();
        typedef pair<int,int> tp;
        queue<tp> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    q.push(tp(i,j));
                }
                else ans[i][j]=-1;
            }
        }
        tp d[4]={tp(-1,0),tp(1,0),tp(0,1),tp(0,-1)};
        while(q.size()){
            // cout<<"while"<<endl;
            tp front=q.front();
            int x=front.first, y=front.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=x+d[i].first,ny=y+d[i].second;
                // cout<<nx<<" "<<ny<<endl;
                if(nx>=0 && nx<rows && ny>=0 && ny<cols && ans[nx][ny]==-1){
                    ans[nx][ny]=ans[x][y]+1;
                    q.push(tp(nx,ny));
                }
            }
        }
        return ans;
    }
};