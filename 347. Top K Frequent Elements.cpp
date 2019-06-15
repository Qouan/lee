class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int,int>hash;
    for(int n:nums){
        hash[n]+=1;
    }
    vector<vector<int> >bucket(nums.size()+1);
    for(auto h:hash){
        bucket[h.second].push_back(h.first);
    }
    vector<int>sol;
    for(int i=nums.size();i>=0&&sol.size()<k;--i){
        sol.insert(sol.end(),bucket[i].begin(),bucket[i].end());
    }
    return sol;
    }
};