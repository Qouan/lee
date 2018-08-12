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
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)return ;//最少有三个节点
    ListNode*f=head,*s=head;
    while(f->next&&f->next->next)
    {
        f=f->next->next;
        s=s->next;
    }
    if(f->next!=NULL)s=s->next;//节点数为偶数
    ListNode*root=s->next;
    s->next=NULL;
cout<<root->val;
        ListNode*p=root->next;
        s=root;
    while(p!=NULL)
    {
        root->next=p->next;
        p->next=s;
        s=p;
        p=root->next;
    }root=s;
    f=head;
    while(root!=NULL)
    {
        s=root->next;
        root->next=f->next;
        f->next=root;
        f=f->next->next;
        root=s;
    }}
};
