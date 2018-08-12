class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>kmax;
        for(auto n:nums)
        {
            kmax.insert(n);
            if(kmax.size()>k)kmax.erase(kmax.begin());
        }
        return *(kmax.begin());
    }
};
