class Solution {
public:
    bool reorderedPowerOf2(int N) {
        if(N==0)return false;
    string str=to_string(N);
    sort(str.begin(),str.end());
    do{
        if(str[0]=='0')continue;
        int tmp=atoi(str.c_str());
        if((tmp&(tmp-1))==0)return true;
    }while(next_permutation(str.begin(),str.end()));
    return false;
    }
};
