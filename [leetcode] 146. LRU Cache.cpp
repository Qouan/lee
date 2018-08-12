//https://blog.csdn.net/qq508618087/article/details/50995188
/*思路: 这题的大致思路就是用一个hash表来保存已经存在的key, 然后用另外一个线性容器来存储其key-value值, 我们可以选择链表list, 因为需要调整结点的位置, 而链表可以在O(1)时间移动结点的位置, 数组则需要O(n). 

如果新来一个put请求, 我们先去查hash表

1. 如果已经存在了这个key, 那么我们需要更新其value, 然后将其在list的结点位置移动到链表首部.

2. 如果不存在这个key, 那么我们需要在hash表和链表中都添加这个值, 并且如果添加之后链表长度超过最大长度, 我们需要将链表尾部的节点删除, 并且删除其在hash表中的记录



如果来了一个get请求, 我们仍然先去查hash表, 如果key存在hash表中, 那么需要将这个结点在链表的中的位置移动到链表首部.否则返回-1.

另外一个非常关键的降低时间复杂度的方法是在hash中保存那个key在链表中对应的指针, 我们知道链表要查找一个结点的时间复杂度是O(n), 所以当我们需要移动一个结点到链表首部的时候, 如果直接在链表中查询那个key所对于的结点, 然后再移动, 这样时间复杂度将会是O(n), 而一个很好的改进方法是在hash表中存储那个key在链表中结点的指针, 这样就可以在O(1)的时间内移动结点到链表首部.
*/
class LRUCache
{
    unordered_map<int,list<pair<int,int>>::iterator>hash;
    list<pair<int,int>>cache;
    int size;
public:
    LRUCache(int capacity):size(capacity)
    {

    }

    int get(int key)
    {
        auto it=hash.find(key);
        if(it==hash.end())return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value)
    {
        auto it=hash.find(key);
        if(it!=hash.end())
        {
            it->second->second=value;
            cache.splice(cache.begin(), cache, it->second);
            return ;
        }
        cache.insert(cache.begin(),make_pair(key,value));
        hash[key]=cache.begin();
        if(cache.size()>size)
        {
            hash.erase(cache.back().first);
            cache.pop_back();
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
