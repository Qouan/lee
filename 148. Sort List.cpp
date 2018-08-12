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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
	ListNode*p=head->next;
	head->next=NULL;
	ListNode*h;
	while(p!=NULL)
	{
		ListNode*s=new ListNode(p->val);
		h=head;
		while(h!=NULL){
		if(s->val<=head->val){
			s->next=head;
			head=s;
			break;
		}
		else if(h->next==NULL){
		h->next=s;
		break;}
		else if(s->val>h->val&&s->val<=h->next->val)
		{
			s->next=h->next;
			h->next=s;
            break; 
		}
		else NULL;
		h=h->next;
	  }
		p=p->next;
	}
	return head;
    }
};
