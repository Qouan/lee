#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<string> > solveNQueens(int n) {

}
bool match(vector<int> v){
  int rows=v.size();
  for(int i=0;i<rows;++i){
      for(int j=i+1;j<rows;++j){
          if(abs(v[i]-v[j])==j-i||abs(v[i]-v[j])==0)return 0;
        }
    }
  return 1;
}

vector<vector<int> >out;
void find(int n,int row,vector<int> &res){
  for(;row<n;++row){
    for(int col=0;col<n;++col){
        res.push_back(col);
        if(match(res))
          find(n,row+1,res);
        res.pop_back();
      }
    return;
    }
  out.push_back(res);
}

int main()
{
      vector<int> res;
      find(4,0,res);
      for(int i=0;i<2;i++){
        for(int j=0;j<4;j++)
          {
            cout<<out[i][j];
          }
        cout<<endl;
        }
}
