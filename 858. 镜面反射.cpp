class Solution {
public:
    int mirrorReflection(int p, int q) {
      //思路:将镜面向上翻转
        int times=1;
    while(q*times%p!=0)++times;
    if(times%2==0)return 2;
    if(q*times%(2*p)==0)return 0;
    return 1;
    }
};
