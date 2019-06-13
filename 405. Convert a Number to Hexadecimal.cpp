class Solution {
public:
    unsigned int twoCimplement(int num){
    if(num>=0)return num;
    unsigned int t=(unsigned int)(num);
    return t;
}

string oneToHex(int num){
    if(num>=16||num<0)
        return "?";
    if(num<10)return to_string(num);
    return string(1,char('a'+num-10));
}
string toHex(int num) {
    string res="";
    unsigned n=twoCimplement(num);
    while(n>=16){
        res=oneToHex(n%16)+res;
        n/=16;
    }
    res=oneToHex(n)+res;
    return res;
}
};