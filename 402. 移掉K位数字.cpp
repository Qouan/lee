class Solution {
public:
    string removeKdigits(string num, int k) {
       if(k>=num.size())return "0";
    while (k--) {
        int i;
        for (i = 1; i < num.size(); ++i) {
            if (num[i] < num[i - 1])
            {
                //num.erase(i - 1, 1);
                break;
            }
        }
        num.erase(i-1,1);
    }
    int j=0;
    while(j<num.size()&&num[j]=='0')++j;
    if(j==num.size())return "0";
    return num.substr(j);}
};
