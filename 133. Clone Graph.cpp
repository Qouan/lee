//深搜
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
   unordered_map<UndirectedGraphNode*,UndirectedGraphNode*>hash;
UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
{
    if(node==NULL)return NULL;
    if(hash.count(node))return hash[node];
    hash[node]=new UndirectedGraphNode(node->label);
    for(auto n:node->neighbors)
    {   
        //UndirectedGraphNode*p=cloneGraph(n);
        hash[node]->neighbors.push_back(cloneGraph(n));
    }
    return hash[node];
}
};
