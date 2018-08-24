class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.empty())return 0;
         vector<int>res;

    int start=0;
    while(start<A.size()-1) {
        int diff = A[start + 1] - A[start];
        res.push_back(start);
        int i;
        for (i = start + 2; i < A.size() && A[i] - A[i - 1] == diff; ++i);
        if (i - start > 1)res.push_back(i - 1);
        else res.pop_back();
        start = i-1;
    }int sum=0;
    for(int i=0;i<res.size();i+=2)
    {
        if(res[i+1]-res[i]>1)
        cout<<res[i]<<" "<<res[i+1]<<endl;
        int distance=res[i+1]-res[i]-1;
        sum+=(distance+1)*distance/2;
    }
    return sum;
    }
};