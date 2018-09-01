/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:vector<int>data;int index=-1;
    void init(vector<NestedInteger> &nestedList,vector<int>&data)
    {
        for(auto&n:nestedList)
        {
            if(n.isInteger())
         {
               
                int a=n.getInteger();
                cout<<a;
             data.push_back(a);
                for(auto&c:data)cout<<c<<endl;
         }
            else
           init(n.getList(),data);
        }//for(auto&a:data)cout<<a<<endl;
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        init(nestedList,data);
    }

    int next() {
        //for(auto&a:data)cout<<a;
        ++index;//cout<<index;
        return data[index];
    }

    bool hasNext() {
        //for(auto&a:data)cout<<a;
        cout<<index<<this->data.size();
        // if(index==data.size()-1)return false;
        // return true;
        // cout<<index<<data.size();
        int a=index<this->data.size()-1;

	//注意data.size()是无符号整形,而index是整形,不能直接比较
        return (index!=static_cast<int>(data.size())-1?true:false);
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
