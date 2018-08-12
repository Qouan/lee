class Solution {
public:
    stack<int>stk;
int evalRPN(vector<string>& tokens)
{
	int l,r;
	int res;
	for(auto num:tokens)
	{
        int n=atoi(num.c_str());
		if(n!=0||num[0]=='0')stk.push(n);
		else{
			r=stk.top();stk.pop();
			l=stk.top();stk.pop();
			res=op(l,r,num);
			stk.push(res);
		}
	}return stk.top();
}
    
int op(int l,int r,string& ch)
{
	if(ch=="+")return l+r;
	if(ch=="-")return l-r;
	if(ch=="/")return l/r;
	if(ch=="*")return l*r;
}
};
