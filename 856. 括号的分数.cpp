class Solution {
public:
   int calculate(string&str,int s,int e)
{
    int start = s;
    int end;
    int sum = 0;
    while (start<=e) {
        int l = 0, r = 0;
        for (end = start; end <=e; ++end) {
            if (str[end] == '(')++l;
            else ++r;
            if (l == r) break;
        }
        //边界情况
        if(start+1==end)sum+=1;
        else
        sum += 2*calculate(str, start+1, end-1);
        start = end + 1;
    }
       return sum;
}
int scoreOfParentheses(string S) {
    if (S.size() < 2)return 0;
    return calculate(S,0,S.size()-1);
}
};
