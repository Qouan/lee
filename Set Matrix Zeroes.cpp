void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
	   int n=matrix[0].size();
	   set<int>position;
	   vector<int>rows;
	   for(int i=0;i<m;++i)
	   {
			  for(int j=0;j<n;++j)
			  {
					 if(matrix[i][j]==0){position.insert(j);rows.push_back(i);}
			  }
	   }
	   for(int i=0;i<m;++i)
	   {
			  if(find(rows.begin(),rows.end(),i)!=rows.end()){
			  for(int j=0;j<n;++j)
			  {
					 matrix[i][j]=0;
			  }continue;}
			  for(set<int>::iterator j=position.begin();j!=position.end();++j)matrix[i][*j]=0;
	   }
    }
