class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         vector<int>ret;
   int len= static_cast<int>(nums.size());
//��Ŀ�����ݱ�ɸ���,�ȱ�����ԭ�������ֱ����˷��ʼ�¼
    for(int i=0;i<len;++i)
    {
        int idx=abs(nums[i])-1;
        if(nums[idx]<0)ret.push_back(idx+1);
        nums[idx]*=-1;
    }
    return ret;
    }
};