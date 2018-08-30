class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
       //cout<<INT_MAX;
        sort(A.begin(),A.end());
         for(auto a:A)cout<<a<<" ";
        cout<<endl;
        unordered_map<long long int,long long int>hash;
    for(auto&a:A)hash[a]=1;
    int len=A.size();
        long long int M=pow(10,9)+7;
       // cout<<M;
    for(int i=0;i<len;++i)
    {
        for(int j=0;j<i;++j)
        {
            if(A[i]%A[j]==0&&hash.count(A[i]/A[j]))
                hash[A[i]]+=hash[A[j]]*hash[A[i]/A[j]];
        }
    }
    long long int sum=0;
    for(auto&h:hash)
    {sum+=h.second;
    sum=sum%M;
    }
    return sum;
    }
};