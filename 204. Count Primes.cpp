//用ｖｅｃｔｏｒ比ｓｅｔ好，Ｏ（１）
//i<sqrt(n)
class Solution {
public:
    int countPrimes(int n) {
    if(n<=2)return 0;
		vector<bool>s(n,false);
		int count=1;
		int up=sqrt(n);
		for(int i=3;i<n;i+=2)
		{
			if(!s[i]){++count;
			if(i>up)continue;
			for(int j=i*i;j<n;j+=i)
			{
				if(s[j])continue;
				s[j]=true;
			}}
		}
		return count;
	}
               };
