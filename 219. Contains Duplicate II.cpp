//ｈａｓｈ表＋ｖｅｃｔｏｒ
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int> >hash;
        for(int i=0;i<nums.size();++i)
        {
           for(auto pos:hash[nums[i]])
               if(i-pos<=k)return true;
            hash[nums[i]].push_back(i);
        }
        return false;
    }
};
