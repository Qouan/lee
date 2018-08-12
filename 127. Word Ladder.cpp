//深搜,建立map当做visited表,运行的时候查找邻接节点
class Solution {
public:
   struct Node
{
	   string word;
	   int lne;
	   Node(string s,int len=1):word(s),lne(len){}
};
bool onlywoneword(string&s,string&t)
{
	   int flag=0;
	   for(int i=0;i<s.size();++i)
	   {
			  if(s[i]!=t[i])flag++;
			  if(flag==2)return false;
	   }if(flag==0)return false;
	   return true;
}

int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	   if(beginWord==endWord)return 0;
	   queue<Node*>myqueue;
	   Node *root=new Node(beginWord);
	   myqueue.push(root);
	   unordered_map<string,bool>used;
	   for(auto wordlt:wordList)used.emplace(wordlt,false);
	    if(used.count(endWord)==0)return 0;
	   while(!myqueue.empty())
	   {
			  Node* q=myqueue.front();
              myqueue.pop();
              if(q->word==endWord)return q->lne;
			  for(auto wordlt:wordList)
			  {
					 if(!onlywoneword(q->word,wordlt))continue;//不是只差一个字符的两个字符串
					 if(used.count(wordlt)!=0&&used[wordlt]==false)
					 {
							used[wordlt]=true;
							Node* p=new Node(wordlt,q->lne+1);
							myqueue.push(p);
					 }
			  }
	   }
     return 0;
}
};
