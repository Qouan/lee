//解决一对多和多对一问题
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m;
        set<char>unique;
        for(int i=0;i<s.size();++i)
        {
            if(!m.count(s[i]))
            {
                m[s[i]]=t[i];
                if(unique.count(t[i]))return false;
                unique.insert(t[i]);
            }
            else
            {
                if(m[s[i]]!=t[i])return false;
            }
        }swap(s,t);
        
           return true; 
    }
};
