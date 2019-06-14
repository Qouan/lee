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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL)
        return head;
    ListNode*p=head,*s=head->next,*e=s;
    while(e!=NULL&&e->next!=NULL){
        p->next=e->next;
        e->next=e->next->next;
        p=p->next;
        p->next=s;
        e=e->next;
    }
    return head;
    }
};