class Solution {
public:
   bool match(vector<int>&a,vector<int>&b)
{
    for(int i=0;i<26;++i)
    {
        if(a[i]==1&&b[i]==1)
            return false;
    }
    return true;
}
int maxProduct(vector<string>& words)
{
    vector<vector<int> >mat(words.size(),vector<int>(26));
    int row=0;
    for(auto&str:words)
    {
        vector<int>bit(26);
        for(auto&s:str)
            bit[s-'a']=1;
        mat[row]=bit;
        ++row;
    }

    int maxpro=0;
    for(int i=0;i<mat.size();++i)
    {
        for(int j=i+1;j<mat.size();++j)
        {
            if(match(mat[i],mat[j]))
            {
                int pro;
                if((pro=words[i].size()*words[j].size())>maxpro)
                    maxpro=pro;
            }
        }
    }
    return maxpro;
}
};
