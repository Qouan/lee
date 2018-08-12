class Solution {
    private:vector<int>res;
public:
    void genera(bitset<32>&grcd,int k)
{
	   if(k==-1)  {
	   res.push_back(grcd.to_ulong());
	   return;}
	   genera(grcd,k-1);
	   grcd.flip(k);
	   genera(grcd,k-1);
}

vector<int> grayCode(int n)
{
	   bitset<32> grcd;
	    genera(grcd,n-1);return res;
}
};
