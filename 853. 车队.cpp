class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size()==0)return 0;
        if(position.size()==0)return 0;
    map<int,double,greater<int>>hash;
    for(int i=0;i<position.size();++i)
    {
        double a=(target-position[i])/double(speed[i]);
        hash[position[i]]=a;
    }int res=0;double last=0;
    for(auto&h:hash)
    {
        if(h.second>last)
        {
            ++res;
            last=h.second;
        }
    }
    return res;
    }
};