class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        vector<vector<int>>res;
    int count=R*C;
    int martin=4;
    int x=r0+1,y=c0-1;
    if(r0<R&&r0>=0&&c0>=0&&c0<C){
        res.emplace_back(vector<int>{r0,c0});
        --count;}
    ++c0;
    if(r0<R&&r0>=0&&c0>=0&&c0<C){
        res.emplace_back(vector<int>{r0,c0});
        --count;}
    ++r0;
    if(r0<R&&r0>=0&&c0>=0&&c0<C){
        res.emplace_back(vector<int>{r0,c0});
        --count;}
    --c0;
    if(r0<R&&r0>=0&&c0>=0&&c0<C){
        res.emplace_back(vector<int>{r0,c0});
        --count;}
    r0=x,c0=y;
    while(count>0)
    {
        int x=r0+1,y=c0-1;
        for(int i=1;i<martin;++i)
        {
            if(r0<R&&r0>=0&&c0>=0&&c0<C)
            {
                res.emplace_back(vector<int>{r0,c0});
                --count;
            }--r0;
        }++c0,++r0;
        for(int i=1;i<martin;++i)
        {
            if(r0<R&&r0>=0&&c0>=0&&c0<C)
            {
                res.emplace_back(vector<int>{r0,c0});
                --count;
            }++c0;
        }--c0,++r0;
        for(int i=1;i<martin;++i)
        {
            if(r0<R&&r0>=0&&c0>=0&&c0<C)
            {
                res.emplace_back(vector<int>{r0,c0});
                --count;
            }++r0;
        }--r0,--c0;
        for(int i=1;i<martin;++i)
        {
            if(r0<R&&r0>=0&&c0>=0&&c0<C)
            {
                res.emplace_back(vector<int>{r0,c0});
                --count;
            }--c0;
        }
        r0=x,c0=y;
        martin+=2;
    }
    return res;
    }
};
