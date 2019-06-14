class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
      int a1=INT_MAX,a2=INT_MAX;
  for(auto n:nums){
      if(n<=a1){
          a1=n;
      }else if(n<=a2){
          a2=n;
      }else{
          return true;
      }
  }
    return false;}
};