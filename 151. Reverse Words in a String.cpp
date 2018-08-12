class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        istringstream is(s);
        string res="";
        while(is>>s)
        {
            reverse(s.begin(),s.end());
            res+=s+" ";
        }if(!res.empty())res.pop_back();
        s=res;
    }
};
