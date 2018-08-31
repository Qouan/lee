class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      if(amount==0)return 0;
    unordered_map<int,int>hash;
    for(int j=1;j<=amount;++j)hash[j]=INT_MAX;
    sort(coins.begin(),coins.end(),greater<int>());
    int rows= static_cast<int>(coins.size());
    for(int i=0;i<rows;++i)
    {
        for(int j=1;j<=amount;++j)
        {
            if(j-coins[i]>0&&hash[j-coins[i]]!=INT_MAX)
                hash[j]=min(hash[j],hash[j-coins[i]]+1);
            if(j%coins[i]==0)
                hash[j]=min(hash[j],j/coins[i]);
            //cout<<j<<":"<<hash[j]<<" ";
        }

    }if(hash[amount]!=INT_MAX)return hash[amount];
    return -1;}
};
