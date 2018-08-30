class Solution {
public:
    string fractionToDecimal(long long int  numerator, long long int denominator) {
       if(numerator%denominator==0)return to_string(numerator/denominator);
    int flag=1;
    if(numerator*denominator<0){numerator*=-1;flag=-1;}
    string pre=to_string(numerator/denominator)+".";
    string str="";
    map<long long int,int>chushu;
    long long int yushu=numerator%denominator*10;
    long long int pos=0;
    chushu[yushu]=pos;++pos;
    long long int temp;
    while((temp=yushu%denominator)!=0)
    {
        str+=to_string(yushu/denominator);
        yushu=temp*10;
        if(chushu.count(yushu))
        {
            str.insert(chushu[yushu],"(");
            str+=")";
            if(flag==-1)return "-"+pre+str;
            return pre+str;
        }
        chushu[yushu]=pos;
        ++pos;
    }str+=to_string(yushu/denominator);
    if(flag==-1)return "-"+pre+str;
    return pre+str;}
};
