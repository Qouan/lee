class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>fre;
    for(auto&n:nums)
    {
        ++fre[n];
    }
    vector<pair<int,int> >data;
    for(auto&f:fre)
    {
        data.push_back(make_pair(f.first,f.second));
    }
    sort(data.begin(),data.end(),[](pair<int,int>a,pair<int,int>b)->bool{return a.second>b.second;});
    vector<int>ret;
    for(int i=0;i<k;++i)
        ret.push_back(data[i].first);
    return ret;
    }
};
