class Solution {
public:
   bool validNum(string&str)
{
    int len= static_cast<int>(str.size());
    int i;
    for(i=0;i<len;++i)
    {
        if(str[i]=='.')
        {
            string left=str.substr(0,i);
            if(left.size()>1&&left[0]=='0')
                return false;
            if(str.back()=='0')
                return false;
            break;
        }
    }
    if(i==len&&str.size()>1&&str[0]=='0')return false;
    return true;
}
vector<string>split(string&str)
{
    vector<string>re;
    
    for(int i=1;i<str.size();++i)
    {
        string temp=str;
        temp.insert(i,".");
        re.push_back(temp);
    }
    re.push_back(str);
    return re;
}
vector<string> ambiguousCoordinates(string S)
{
    S=S.substr(1,S.size()-2);
    int len= static_cast<int>(S.size());
    vector<string>ret;
    for(int i=1;i<len;++i)
    {
        string left=S.substr(0,i);
        string right=S.substr(i);
        vector<string>re1=split(left);
        vector<string>re2=split(right);
        for(int j=0;j<re1.size();++j)
        {
            for(int k=0;k<re2.size();++k)
            {
                if(validNum(re1[j])&&validNum(re2[k])) {
                    string path = "(";
                    path += re1[j] + ", " + re2[k] + ")";
                    ret.push_back(path);
                }
            }
        }
    }
    return ret;
}
};