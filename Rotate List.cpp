#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;


 struct ListNode {
      int val;
 ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

    ListNode* rotateRight(ListNode* head, int k) {
      ListNode*p=head;
                 int leng=1;
                 while(p->next){p=p->next;leng++;}
                 p->next=head;
                 k=k-k%leng;
                while(k--)p=p->next;
                 head=p->next;
                 p->next=NULL;
               return head;
    }

    int main()
    {
         ListNode h(1);
         ListNode *head=&h;
         ListNode*p=head;

      for(int i=2;i<6;++i)
         {
              ListNode*s=(ListNode*)malloc(sizeof(ListNode));
              s->val=i;
              s->next=NULL;
            p->next=s;
              p=p->next;
          }
      rotateRight(head,2);
    }


