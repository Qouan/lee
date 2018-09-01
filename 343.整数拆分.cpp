class Solution {
public:
    int integerBreak(int time) {
        if(time==2)return 1;
        if(time==3)return 2;
        int time3=time/3;
        if(time%3==0)return pow(3,time3);
        if(time%3==1)return pow(3,time3-1)*4;
        if(time%3==2)return pow(3,time3)*2;
    }
