#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;
struct ListNode {
	 int val;
	  ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
  };
 inline ListNode* cycle(ListNode*head)
 {
	   ListNode*fast=head,*slow=head;
	   while(fast->next!=NULL)
	   {
			  head=head->next->next;
			  slow=head->next;
			  if(head==slow)return head;
	   }return NULL;
 }

 ListNode *detectCycle(ListNode *head)
 {
		if(head==NULL)return head;
	   ListNode*f=cycle(head);
	   if(f==NULL)return NULL;
	   ListNode*s=head;
	   while(s!=f){s=s->next;f=f->next;}
	   return f;
 }
 int main()
 {
	   ListNode*root=new ListNode(1);
		ListNode*t=new ListNode(2);
		root->next=t;
		t->next=root;
		ListNode*p=detectCycle(root);
		cout<<p->val;
 }



