class Solution {
public:
    int thirdMax(vector<int>& nums) {
        vector<int>minHeap;
    for(auto n:nums){
        if(minHeap.size()<3&&find(minHeap.begin(),minHeap.end(),n)==minHeap.end()){
            minHeap.push_back(n);
            if(minHeap.size()==3)make_heap(minHeap.begin(),minHeap.end(),greater<int>());
        }
        else{
            if(n>minHeap[0]&&find(minHeap.begin(),minHeap.end(),n)==minHeap.end()){
                minHeap.push_back(n);
                push_heap(minHeap.begin(),minHeap.end(),greater<int>());
                pop_heap(minHeap.begin(),minHeap.end(),greater<int>());
                minHeap.pop_back();
            }
        }
    }
        
    sort(minHeap.begin(),minHeap.end());
        if(minHeap.size()<3)return minHeap.back();
    return minHeap[0];
    }
};