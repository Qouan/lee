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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)return NULL;
        while(head!=NULL&&head->val==val)head=head->next;
        ListNode*p=head;
        ListNode*pre;
        while(p!=NULL)
        {
            pre=p;
            p=p->next;
           while(p!=NULL&&p->val==val){pre->next=p->next;p=pre->next;}
        }
        return head;
    }
};
