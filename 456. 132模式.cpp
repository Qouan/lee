class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      int len= static_cast<int>(nums.size());
    if(len<3)return false;
    int i=0;
    while(i<len-1) {
        while (i < len - 1 && nums[i] >= nums[i + 1])++i;
        int j = i + 1;
        while (j < len && nums[j] > nums[j - 1])++j;
        --j;
        for (int k = j + 1; k < len; ++k) {
            if (nums[k] > nums[i] && nums[k] < nums[j])
                return true;
        }
        i=j+1;
    }
    return false;}
};
