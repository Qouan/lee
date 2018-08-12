class Solution {
public:
  
    struct Node
{
	   string word;
	   vector<string>list;
	   Node(string s):word(s){}
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
      unordered_map<string,bool>used;
    vector<vector<string>>res;
     queue<Node*>myqueue;
    void  search(string &beginWord, string& endWord, Node *q, vector<string>& wordList)
    {
         if(onlywoneword(q->word,endWord)){q->list.push_back(endWord);res.push_back(q->list);return;}
	     else{for(auto wordlt:wordList)
			  {
					 if(!onlywoneword(q->word,wordlt))continue;//不是只差一个字符的两个字符串
					 if(used.count(wordlt)!=0&&used[wordlt]==false)
					 {
							used[wordlt]=true;
							Node* p=new Node(wordlt);
							p->list=q->list;
							p->list.push_back(wordlt);
							myqueue.push(p);
                            search(beginWord,endWord,p,wordList);
                                myqueue.pop();
                         used[wordlt]=false;
					 }
			  }}
	   }
    

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord)return {{beginWord}};
	  
	   Node *root=new Node(beginWord);
	   root->list.push_back(beginWord);
	   for(auto wordlt:wordList)used.emplace(wordlt,false);
	   if(used.count(endWord)==0)return {};
       search(beginWord,endWord,root,wordList);
        return res;
	   
    }
}
