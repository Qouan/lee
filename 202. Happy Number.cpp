class Solution {
public:
    bool isHappy(int n) {
       unordered_map<int,int>m;
        int sum;
        while(n!=1)
        {
            sum=0;
       while(n)
       {
           sum+=(n%10)*(n%10);
           n/=10;
       }
            n=sum;
       if(m[sum]++>0)
           break;
        }
        return n==1;
    }
};
