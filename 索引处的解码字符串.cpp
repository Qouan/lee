class Solution {
public:
   char search(vector<unsigned long long int>&dp,vector<string>&ss,int K)
{
    unsigned long long int ba=dp.back();
    dp.pop_back();
       int t=dp.empty()?0:dp.back();
    K=K%(t+ss.back().size());
       cout<<K<<" ";
    if(dp.empty()||K>=dp.back())
    {
        if(dp.empty())return ss.back()[K%ss.back().size()];
        return ss.back()[K-dp.back()];
    } else{
        ss.pop_back();
        return search(dp,ss,K);
    }
}
string decodeAtIndex(string S, int K)
{
    if(!isdigit(S.back()))S+="1";
    int len=S.size();
    int last_pos=0;
    vector<unsigned long long int>dp;
    vector<string>ss;
    for(int i=0;i<len;++i)
    {
        if(isdigit(S[i])==1) {
            unsigned long long int pro=S[i]-'0';
            int j=i+1;
            while(j<len&&isdigit(S[j])){pro*=S[j]-'0';++j;}
            if(last_pos==0) {
                dp.push_back((i - last_pos ) * (pro));
                ss.push_back(S.substr(last_pos , i - last_pos));
            }
            else {
                dp.push_back((i - last_pos  + dp.back()) * (pro));
                ss.push_back(S.substr(last_pos , i - last_pos));
            }
            last_pos=j;
            i=j-1;
            if(dp.back()>=K)break;
        }
    }
    //for(auto&st:dp)cout<<st<<" ";
    return string(1,search(dp,ss,K-1));
}
};
