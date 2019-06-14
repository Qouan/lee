class Solution {
public:
    int bulbSwitch(int n) {
       if(n==0)return 0;
    int temp=3,start=0;
    int res=1;
    while(n-start>temp){
        res+=1;
        start+=temp;
        temp+=2;
    }
    return res;}
};