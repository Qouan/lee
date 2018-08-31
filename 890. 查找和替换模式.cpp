class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>res;
    int len=pattern.size();
    for(auto&str:words)
    {
        if(str.size()!=len)continue;
        unordered_map<char,char>mapped1,mapped2;
        int i;
        for(i=0;i<len;++i)
        {
            if(!mapped1.count(str[i]))
                mapped1[str[i]]=pattern[i];
            else
            {
                if(mapped1[str[i]]!=pattern[i])
                    break;
            }

            if(!mapped2.count(pattern[i]))
                mapped2[pattern[i]]=str[i];
            else
            {
                if(mapped2[pattern[i]]!=str[i])
                    break;
            }
        }if(i==len)res.push_back(str);
    }
    return res;
    }
};
