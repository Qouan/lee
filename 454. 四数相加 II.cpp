class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
       unordered_map<int,int>record;
    for(int i=0;i<A.size();++i)
        for(int j=0;j<B.size();++j)
            ++record[A[i]+B[j]];
    int sum=0;
    for(int i=0;i<C.size();++i)
        for(int j=0;j<D.size();++j)
        {
            if(record.count(0-C[i]-D[j]))
                sum+=record[0-C[i]-D[j]];
        }
    return sum;
    }
};
