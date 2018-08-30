class Solution {
public:
  int opnumber(int a,int b,char op)
{
    if(op=='+')return a+b;
    if(op=='-')return a-b;
    if(op=='*')return a*b;
    return a/b;
}
int calculate(string s)
{

    for(int i=0;i<s.size();++i)
    {
        if(s[i]==' '){s.replace(i,1,"");
        --i;}
    }

    stack<int>num;
    stack<char>op;
    int len= static_cast<int>(s.size());
    vector<string>split;
    int start=0,end;
    while (start<len) {
        for (end = start; end < len; ++end) {
            if(!isdigit(s[end]))
            {
                if(op.empty())
                {
                    num.push(atoi(s.substr(start,end-start).c_str()));
                    op.push(s[end]);
                }
                else
                {
                    if(op.top()=='*'||op.top()=='/'||s[end]=='-'||s[end]=='+')
                    {
                        int top=num.top();
                        num.pop();
                        num.push(opnumber(top,atoi(s.substr(start,end-start).c_str()),op.top()));
                        op.pop();
                        if(!op.empty())
                        if(op.top()=='*'||op.top()=='/'||s[end]=='-'||s[end]=='+')
                        {
                            int a=num.top();
                            num.pop();
                            int b=num.top();
                            num.pop();
                            num.push(opnumber(b,a,op.top()));
                            op.pop();

                        }op.push(s[end]);

                    }
                    else
                    {
                        num.push(atoi(s.substr(start,end-start).c_str()));
                        op.push(s[end]);
                    }
                }
                break;
            }
        }
        if(end==len)num.push(atoi(s.substr(start).c_str()));
        start=end+1;
    }
    while(!op.empty())
    {
        int a=num.top();
        num.pop();
        int b=num.top();
        num.pop();
        num.push(opnumber(b,a,op.top()));
        op.pop();
    }
    return num.top();
}
};
