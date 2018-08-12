class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       bitset<32>bin(n);
	   string bina_s="";
	   int i=0;
	   while(i<32){
	   bina_s+=string(1,bin[i]+'0');
	   ++i;}
	   bitset<32> res(bina_s);
	   return res.to_ulong();
    }
};
