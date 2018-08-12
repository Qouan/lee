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
    ListNode* reverseList(ListNode* head) {
       if(head==NULL)return NULL;
       ListNode*root=head->next;
       head->next=NULL;
       while(root)
       {
           ListNode*cur=root;
           root=root->next;
           cur->next=head;
           head=cur;
       }
       return head;
    }
};
