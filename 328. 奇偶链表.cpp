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
    ListNode* oddEvenList(ListNode* head)
{
    if(head== nullptr)return head;

    ListNode*pre=head,*tail=head->next;
    while(1)
    {
        if(tail== nullptr)break;
        ListNode*tmp=tail->next;
        if(tmp== nullptr)break;
        tail->next=tail->next->next;
        tail=tail->next;

        tmp->next=pre->next;
        pre->next=tmp;
        pre=pre->next;
    }
    return head;}
};
