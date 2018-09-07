class Solution {
public:
    int hammingDistance(int x, int y) {
         bitset<32>num=x^y;
    return num.count();
    }
};