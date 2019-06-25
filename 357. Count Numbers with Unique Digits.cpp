class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int count=1,i=1,k=9,digit=9;
   while(i<=min(10,n)){
       count+=digit;
       digit*=k;
       ++i;
       --k;
   }
    return count;
    }
};