class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> candidate(1,1);
    vector<int> coefficient(primes.size(),0);
    vector<int> compare(primes.size());
    if(n==1)return 1;
    int minNum=0;
    while (--n){
        for(int i=0;i<primes.size();++i){
            compare[i]=candidate[coefficient[i]]*primes[i];
            }
        minNum=*min_element(compare.begin(),compare.end());
        candidate.push_back(minNum);
        for(int j=0;j<primes.size();++j){
            if(minNum==compare[j])
                coefficient[j]+=1;
        }
    }return minNum;}
};