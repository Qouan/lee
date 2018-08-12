//ACGT二进制的后三位都不同,可以用30位的二进制数来保存每个字符串
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)return {};
	   int cur=0;
	   int i=0;
	   while(i<10)cur=cur<<3|(s[i++]&7);
	   unordered_map<int,bool>hash;
	   hash[cur]=true;
	   int mask=0x7ffffff;
	   set<string>res;
	   while(i<s.size())
	   {
			  cur=(cur&mask)<<3|(s[i++]&7);
			  if(hash[cur]==true)res.insert(s.substr(i-10,10));
			  else hash[cur]=true;
	   }
        vector<string>r;
        for(auto s:res)r.push_back(s);
	   return r;
    }
};
