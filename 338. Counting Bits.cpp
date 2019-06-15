class Solution {
public:
    vector<int> countBits(int num) {
         vector<int>res(1,0);
    for(int i=1;i<=num;++i){
        int topush=0;
        int temp=i;
        while (temp>0){
            if((temp&0x1)>0)
                ++topush;
            temp>>=1;
        }res.push_back(topush);
    }
    return res;
    }
};