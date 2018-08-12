class Solution {
public:vector<int>diff;
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i=0;i<gas.size();++i)
        {
            diff.push_back(gas[i]-cost[i]);
        }
        if(accumulate(diff.begin(),diff.end(),0)<0)return -1;
        return search();
    }
    int search(void)
    {
            int sum,pos;
        int len=diff.size();
        for(int i=0;i<diff.size();++i)
        {
            if(diff[i]<0)continue;
            sum=0;pos=i;
            while(sum>=0)
            {
                sum+=diff[pos];
                ++pos;
                if(pos==len)pos=0;
                if(pos==i&&sum>=0)return i;
            }
        }
        return -1;
    }
};
