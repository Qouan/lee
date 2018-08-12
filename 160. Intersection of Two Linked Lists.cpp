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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headB||!headA)return NULL;
	ListNode*tailB=headB;
	while(tailB->next!=NULL)tailB=tailB->next;
	tailB->next=headB;
	ListNode*f=headA,*s=headA;
	while(f!=NULL&&f->next!=NULL)
	{
		f=f->next->next;
		s=s->next;
		if(f==s)
		{
			s=headA;
			while(s!=f){
				s=s->next;
				f=f->next;
			}tailB->next=NULL;
            return s;
		}
	}tailB->next=NULL;return NULL;
    }
};
