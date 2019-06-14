class Solution {
public:
    int longestPalindrome(string s) {
        vector<int>count(52,0);
    for(char ch:s){
        if(islower(ch))++count[int(ch-'a')];
        else ++count[int(ch-'A'+26)];
    }
    int flag=0;
    int res=0;
    for(auto c:count){
        if(c%2==1){
            flag=1;
            res+=c-1;
        } else res+=c;
    }
    return res+flag;
    }
};