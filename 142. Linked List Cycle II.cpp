/*主要思想和上一个算法前面基本一样，也是设置一个快指针fp和一个慢指针sp，所不同的是这回是要求出如果链表存在环，那么求出环入口的起始结点。接下来我们就是要从上面的算法中做出一定程度的改变就可以完成题目的要求了。我首先说一下具体的解法，推导过程后面再说。
如果链表中存在环，那么fp和sp一定会相遇，当两个指针相遇的时候，我们设相遇点为c，此时fp和sp都指向了c，接下来令fp继续指向c结点，sp指向链表头结点head，此时最大的不同是fp的步数变成为每次走一步，令fp和sp同时走，每次一步，那么它们再次相遇的时候即为环的入口结点。
*/
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
    inline ListNode* cycle(ListNode*head)
 {
	   ListNode*fast=head,*slow=head;
	   while(fast->next!=NULL&&fast->next->next!=NULL)
	   {
			  fast=fast->next->next;
			  slow=slow->next;
			  if(fast==slow)return fast;
	   }return NULL;
 }

 ListNode *detectCycle(ListNode *head)
 {
        if(head==NULL||head->next==NULL)return NULL;
	   ListNode*f=cycle(head);
	   if(f==NULL)return NULL;
	   ListNode*s=head;
	   while(s!=f){s=s->next;f=f->next;}
	   return f;
 } 
};
