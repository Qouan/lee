class Solution {private:vector<vector<int> >res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>buck;
        background(k,n,buck);
        return res;
    }
    void background(int k,int n,vector<int>&buck)
    {
        if(buck.size()==k)
        {
            if(accumulate(buck.begin(),buck.end(),0)==n)
                res.push_back(buck);
            return ;
        }
        for(int i=1;i<10;++i)
        {
            if(!buck.empty()&&i<=buck.back())continue;
            buck.push_back(i);
            background(k,n,buck);
            buck.pop_back();
        }
    }
};
