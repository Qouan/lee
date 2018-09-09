class Solution {
public:
   int coe_var,coe_num;
void part(string&equation,unsigned int start,int equa_pos)
{
    unsigned int i=start;
    coe_var=0,coe_num=0;
    char op='+';
    for(;i<equa_pos;++i)
    {
        if(equation[i]=='x')
        {
            if(op!='-')++coe_var;
            else --coe_var;
        }
        if(equation[i]=='+'||equation[i]=='-')
            op=equation[i];
        if(isdigit(equation[i]))
        {
            int num=equation[i]-'0';
            unsigned int j=i+1;
            for(;j<equa_pos&&isdigit(equation[j]);++j)
            {
                num=num*10+equation[j]-'0';
            }
            if(equation[j]=='x') {
                if(op!='-')
                    coe_var += num;
                else coe_var-=num;
                i=j;
            } else{
                if(op!='-')
                    coe_num += num;
                else coe_num-=num;
                i=j-1;
            }
            
        }
    }
}
string solveEquation(string equation)
{
    unsigned int equa_pos= equation.find('=');
    part(equation,0,equa_pos);
    int cv1=coe_var,cn1=coe_num;
    //cout<<cv1<<cn1;
    part(equation,equa_pos+1,equation.size());
    //cout<<coe_var<<coe_num;
    cv1-=coe_var,cn1=coe_num-cn1;
    if(cv1==0&&cn1==0)
        return "Infinite solutions";
    if(cv1==0)
        return  "No solution";
    int ans=cn1/cv1;
    return "x="+to_string(ans);
}
};