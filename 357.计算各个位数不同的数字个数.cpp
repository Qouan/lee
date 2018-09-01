class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
       vector<int>distrib(n+1);
    distrib[0]=1;
    for(int i=1;i<=n;++i)
    {
        int product=9;
        int count=i-1;
        for(int j=9;;--j)
        {
            if(count==0)break;
            product*=j;
            --count;

        }distrib[i]=product+distrib[i-1];
    }
    return distrib[n];}
};
