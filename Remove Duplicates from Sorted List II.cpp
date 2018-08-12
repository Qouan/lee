#82
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       if(!head||!(head->next))return head;
	   vector<int> vals;vals.push_back(head->val);
	    ListNode*p=head->next;
	    int pop_flag=0;
	  while(p)
	  {
			  if(p->val==vals.back()){pop_flag=1;p=p->next;continue;}
			  if(pop_flag){vals.pop_back();pop_flag=0;}
			  vals.push_back(p->val);
              p=p->next;
	  }
    if(pop_flag==1)vals.pop_back();
	 if(vals.empty())return NULL;
     //if(vals.size()==1&&pop_flag==1)return NULL;
        p=head;
	  for(int i=0;i<vals.size();++i)
	  {
			  p->val=vals[i];
			  if(i!=vals.size()-1)
			  p=p->next;
	  }p->next=NULL;
	  return head;
    }
};
