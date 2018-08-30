class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
         sort(people.begin(),people.end(),[](pair<int,int>a,pair<int,int>b)->bool
    {
        if(a.first!=b.first)return a.first<b.first;
        else {
            return a.second > b.second;
        }
    });
//    for(auto&k:people)cout<<k.first<<k.second;
//                                   cout<<endl;
    int len= static_cast<int>(people.size());
    vector<int>pos(len,-1);
    for(int i=0;i<len;++i)
    {
        int count=-1;
        for(int j=0;j<len;++j)
        {
            if(pos[j]==-1)
                ++count;
            if(count==people[i].second) {
                pos[j] = i;
                break;
            }

        }
    }for(auto&s:pos)cout<<s<<" ";
    vector<pair<int,int> >res;
    for(auto&p:pos)
    {
        res.push_back(people[p]);
    }
    return res;}
};
