class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       map<int,vector<vector<int> > >m;
    vector<vector<int> >res;
   for(int i=0;i<nums1.size();++i){
       for(int j=0;j<nums2.size();++j){
           m[nums1[i]+nums2[j]].push_back({nums1[i],nums2[j]});
       }
   }
   for(auto s:m){
       while(!s.second.empty()&&k>0){
           res.push_back(s.second.back());
           s.second.pop_back();
           --k;
       }
   }
    return res;
    }
};