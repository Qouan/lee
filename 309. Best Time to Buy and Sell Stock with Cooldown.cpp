class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if (prices.empty()) 
            return 0;
        int len=prices.size();
     vector<int>buy(len),sell(len);
     buy[0]=-prices[0];
     sell[0]=0;
     for(int i=1;i<len;++i)
     {
         if(i!=1)
            buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
         else buy[i]=max(buy[i-1],-prices[i]);
         sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
     }
     return sell[len-1];}
};