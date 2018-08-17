#include<iostream>
#include<queue>
#include <string>
using namespace std;
vector<string>path;
bool is_additive(string&num,int pos)
{
    int len=path.size();
    if(pos==num.size())
    {
        if(path.size()<3)
            return false;
        if(atoll(path[len-3].c_str())+atoll(path[len-2].c_str())==atoll(path[len-1].c_str()))
            return true;
    }

    for(int i=1;i+pos<=num.size();++i)
    {
        if(path.size()<2)
        {
            string new_str=num.substr(pos,i);
            if(new_str.size()>1&&new_str[0]=='0')return false;
            path.push_back(num.substr(pos,i));
            if (is_additive(num, i + pos))return true;
            path.pop_back();
        }else
        {
            string new_str=num.substr(pos,i);
            if(new_str.size()>1&&new_str[0]=='0')return false;
            if(atoll(path[len-2].c_str())+atoll(path[len-1].c_str())==atoll(new_str.c_str())) {
                path.push_back(num.substr(pos,i));
                if (is_additive(num, i + pos))return true;
                path.pop_back();
            }
            if(atoll(path[len-2].c_str())+atoll(path[len-1].c_str())<atoll(num.substr(pos,i).c_str()))
                return false;
        }
    }return false;
}
bool isAdditiveNumber(string& num)
{
    return is_additive(num,0);
}

