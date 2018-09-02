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
  int add(vector<int>&arr1,vector<int>&arr2)
{
    int carry=0;
    int i,j;
    for(i=arr1.size()-1,j=arr2.size()-1;j>=0;--i,--j)
    {
        int sum=arr1[i]+arr2[j]+carry;
        arr1[i]=sum%10;
        carry=sum/10;
    }
    for(;i>=0;--i)
    {
        if(carry==0)break;
        int sum=arr1[i]+carry;
        arr1[i]=sum%10;
        carry=sum/10;
    }
    return carry;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    vector<int>arr1;
    ListNode*p1=l1;
    while(p1!= nullptr)
    {
        arr1.push_back(p1->val);
        p1=p1->next;
    }

    vector<int>arr2;
    ListNode*p2=l2;
    while(p2!= nullptr)
    {
        arr2.push_back(p2->val);
        p2=p2->next;
    }
     
    if(arr1.size()<arr2.size())swap(arr1,arr2);
    
   // for(auto&p:arr1)cout<<p<<endl;
   //  for(auto&p:arr2)cout<<p<<endl;
    
    int c=add(arr1,arr2);
    auto*head=new ListNode(c);
    p1=head;
    for(int i=0;i<arr1.size();++i)
    {
        auto*p=new ListNode(arr1[i]);
        p1->next=p;
        p1=p1->next;
    }
    if(head->val==0)return head->next;
    return head;
}
};