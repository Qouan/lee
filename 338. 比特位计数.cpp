class Solution {
public:
    vector<int> countBits(int num) {
        if(num==0)return {0};
    vector<int>res{0,1};
    if(num==1)return res;
    int start=1;
    while(1) {
        int end = res.size();
        for (int i = start; i < end; ++i) {
            res.push_back(res[i]);
            if(res.size()-1==num)break;
        }if(res.size()-1==num)break;
        for (int i = start; i < end; ++i) {
            res.push_back(res[i] + 1);
            if(res.size()-1==num)break;
        }if(res.size()-1==num)break;
        start = end;
    }
    return res;
    }
};
