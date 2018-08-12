//前后两次遍历
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        if(len==0)return 0;
        if(len==1)return 1;
        vector<int>c(len,1);
        for(int i=1;i<len;++i)
        {
            if(ratings[i]>ratings[i-1])c[i]=c[i-1]+1;
        }
        for(int i=len-2;i>=0;--i)
        {
            if(ratings[i]>ratings[i+1]&&c[i]<=c[i+1])c[i]=c[i+1]+1;
        }
        int res=accumulate(c.begin(),c.end(),0);
        //if(ratings[0]>ratings[1])res++;
        return res;
    }
}
