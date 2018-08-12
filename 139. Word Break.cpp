class Solution {private:unordered_map<string,bool>myset;
public:
    bool search(string&s,vector<string>& wordDict)
    {
        if(myset.count(s))return myset[s];
        for(auto word:wordDict)
        {
                string left=s.substr(0,word.size());
            
            if(!myset.count(left)||myset[left]==false)continue;
            
                string stemp=s.substr(word.size());
                if(search(stemp,wordDict))return myset[s]=true ;
            
        }
        return myset[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto word:wordDict)myset.emplace(word,true);
       return search(s,wordDict);
    }
};
