//判断回文,定义两个索引分别指向前后,进行比较
class Solution {
public:
    bool isPalindrome(string s) {
         string trans="";
	  
	   for(char ch:s)
	   {
			  if(!isalnum(ch))continue;
			  if(isupper(ch))ch=tolower(ch);
			  trans+=ch;
	   }
        for(int i=0,j=trans.size()-1;i<=j;++i,--j)
        {
            if(trans[i]!=trans[j])return false;
        }
        return true;}
};
