class Solution {
public:
    string addStrings(string num1, string num2) {
        string st="";
    if(num1.size()<num2.size())swap(num1,num2);
    int carry=0;
    reverse(num1.begin(),num1.end());
    reverse(num2.begin(),num2.end());
    num2+=string(num1.size()-num2.size(),'0');
    for(int i=0;i<num1.size();++i){
        int sum=num1[i]-'0'+num2[i]-'0'+carry;
        num1[i]=sum%10+'0';
        carry=sum/10;
    }reverse(num1.begin(),num1.end());
    if(carry>0)num1=to_string(carry)+num1;
    return num1;
    }
};