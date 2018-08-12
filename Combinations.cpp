class Solution {
    private:vector<vector<int> >res;
public:
    void generate(vector<int>&sample, vector<int>&subay,int start,int k,int slected=0)
{
	   if(slected==k){res.push_back(subay);return;}
	   if(k-slected+start>sample.size())return ;
	   for(int i=start;i<sample.size();++i)
	   {
			  subay.push_back(sample[i]);
			  generate(sample,subay,i+1,k,slected+1);
			  subay.pop_back();
	   }return ;
}

    vector<vector<int>> combine(int n, int k) {
        vector<int> sample;
	   vector<int>subay;
	   for(int i=1;i<=n;++i)
	   sample.push_back(i);
	  generate(sample,subay,0,k);
        return res;
    }
};
