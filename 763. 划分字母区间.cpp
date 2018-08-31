class Solution {
public:
    vector<int> partitionLabels(string S) {
         vector<int>bitmap(26);
    for(int i=0;i<S.size();++i)bitmap[S[i]-'a']=i;
    vector<int>res;
    int start=0,end;
    while(start<S.size()) {
        end=bitmap[S[start]-'a'];
        for (int i = start + 1; i < end; ++i) {
            if (bitmap[S[i] - 'a'] > end)end = bitmap[S[i] - 'a'];
        }
        res.push_back(end-start+1);
        start = end + 1;
    }return res;}
};