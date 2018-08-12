//简单回溯问题
class Solution {
public:vector<vector<string>>res;
   vector<vector<string>> partition(string s)
{
        if(s.empty())return {};
	  vector<string>vec;
	  par(s,vec);
	  return res;
}

void par(string &s,vector<string>&vec)
{
	   if(s.empty()){res.push_back(vec);return ;}
	    for(int i=1;i<=s.size();++i)
	   {
			  string left=s.substr(0,i);
			  if(!ispalindrome(left))continue;
			  //palindrome condition
			  vec.push_back(left);
            string right=s.substr(i);
			  par(right,vec);
			  vec.pop_back();
	   }return ;
}

bool ispalindrome(string &s)
{
	   for(int i=0,j=s.size()-1;i<j;++i,--j)
	   {
			  if(s[i]!=s[j])return false;
	   }return true;
}
};
