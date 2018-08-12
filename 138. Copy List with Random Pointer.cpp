/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:unordered_map<RandomListNode*,RandomListNode*>hash;
    RandomListNode *copyRandomList(RandomListNode *head) {
    if(head==NULL)return NULL;
    if(hash.count(head))return hash[head];
    hash[head]=new RandomListNode(head->label);
    hash[head]->next=copyRandomList(head->next);
    hash[head]->random=copyRandomList(head->random);
    return hash[head];
    }
};
