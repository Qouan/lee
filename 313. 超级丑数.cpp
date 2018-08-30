class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len=primes.size();
    vector<int>index(len);
    vector<int>ugly(1,1);
    while(ugly.size()<n)
    {
        vector<int>ans;
        for(int i=0;i<len;++i)
        {
            ans.push_back(ugly[index[i]]*primes[i]);
        }
        int mim=*min_element(ans.begin(),ans.end());
        ugly.push_back(mim);
        for(int i=0;i<len;++i)
        {
            if(ans[i]==mim)
                ++index[i];
        }
    }
    return ugly.back();
    }
};
