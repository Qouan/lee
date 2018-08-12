//快慢指针解决中间环问题
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)return 0;
        ListNode*fast=head->next;
        ListNode*p=head;
        while(p!=fast)
        {
            if(fast->next==NULL||fast->next->next==NULL)return false;
            fast=fast->next->next;
             p=p->next;
        }
        return true;
    }
};
