class Solution {
public:
    set<string>myset;
double  sum;
bool search(string a,string&b, unordered_map<string,unordered_map<string,double>>&hash)
{
    if(a==b)return true;

    for(auto&pa:hash[a])
    {
        if(myset.count(pa.first)) {
            myset.erase(a);
            sum*=hash[a][pa.first];
            //cout<<a<<pa.first<<hash[a][pa.first]<<" ";
            if (search(pa.first, b, hash))return true;
            sum/=hash[a][pa.first];
            //cout<<a<<pa.first<<hash[a][pa.first]<<" ";
            myset.insert(a);
        }
    }

    return false;
}

vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>&
            values, vector<pair<string, string>> queries)
{
    unordered_map<string,unordered_map<string,double>>hash;
    for(int i=0;i<values.size();++i)
    {
        myset.insert(equations[i].first);
        myset.insert(equations[i].second);
        hash[equations[i].first][equations[i].second]=values[i];
        hash[equations[i].second][equations[i].first]=1.0/values[i];
    }
    vector<double>res;
    set<string>tp=myset;
    for(auto&pa:queries)
    {
        if(tp.count(pa.first)&&tp.count(pa.second)) {
            sum = 1;
            myset = tp;
            if(search(pa.first, pa.second, hash))
            res.push_back(sum);
            else res.push_back(-1);
        }else res.push_back(-1);
    }
    return res;
}
};
