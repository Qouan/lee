class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int tail=nums.size()-1;
        while(k--)
        {
            nums.insert(nums.begin(),nums[tail]);
            nums.pop_back();
        }
    }
};
