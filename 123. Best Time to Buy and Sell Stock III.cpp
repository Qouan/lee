//https://www.cnblogs.com/grandyang/p/4281975.html
/*我们定义local[i][j]为在到达第i天时最多可进行j次交易并且最后一次交易在最后一天卖出的最大利润，此为局部最优。然后我们定义global[i][j]为在到达第i天时最多可进行j次交易的最大利润，此为全局最优。它们的递推式为：local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

	  global[i][j] = max(local[i][j], global[i - 1][j])

1. 今天刚买的
那么 Local(i, j) = Global(i-1, j-1)
相当于啥都没干

2. 昨天买的
那么 Local(i, j) = Global(i-1, j-1) + diff
等于Global(i-1, j-1) 中的交易，加上今天干的那一票

3. 更早之前买的
那么 Local(i, j) = Local(i-1, j) + diff
昨天别卖了，留到今天卖
*/

local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)

global[i][j] = max(local[i][j], global[i - 1][j])
	
class Solution {
public:
  
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
       int len=prices.size();
	   int l[len][3]={0};
	   int g[len][3]={0};
	   int diff;
	   
	   for(int i=1;i<len;++i)
	   {	  diff=prices[i]-prices[i-1];
			  for(int j=1;j<3;++j)
			  {
					 l[i][j]=max(g[i-1][j-1]+max(0,diff),l[i-1][j]+diff);
					 g[i][j]=max(g[i-1][j],l[i][j]);
			  }
		}
		return g[len-1][2];	  
    }
};
