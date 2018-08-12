class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32>res(n);
        return res.count();
    }
};
