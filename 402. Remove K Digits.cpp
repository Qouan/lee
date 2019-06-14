class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==0)return num;
        
       while (k>0){
           if(num.size()==1)return "0";
        for(int i=0;i<num.size()-1;++i){
            if(num[i]>num[i+1]){
                num.erase(i,1);
                --k;
                break;
            }
            else if(num[i]==num[i+1]){
                if(i==num.size()-2) {
                    num.erase(i, 1);
                    --k;
                }
                else {
                    continue;
                }
            }
            else{
                while (num[i]<num[i+1]){
                    ++i;
                }
                num.erase(i,1);
                --k;
                break;
            }
        }
            while(num[0]=='0')num.erase(0,1);
           if(num.size()==0)return "0";
           
    }
       if(num.size()==0)return "0"; 
    return num;
    }
};