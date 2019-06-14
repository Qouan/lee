class Solution {
public:
    int index=0;
bool isVal(vector<int>&node){
    if(index>=node.size())return false;
    if(node[index]==-1){
        index+=1;
        return true;
    }
    index+=1;
    if(!isVal(node)){
        return false;
    }
    if(!isVal(node)){
        return false;
    }
    return true;
}
bool isValidSerialization(string preorder){
    int start=0;
    vector<int>node;
    preorder+=",";
    for(int i=0;i<int(preorder.size());++i){
        if(preorder[i]==','){
            if(isdigit(preorder[start])){
                node.push_back(stoi(preorder.substr(start,i-start)));
            }else{
                node.push_back(-1);
            }start=i+1;
        }
    }
    if(int(preorder.size())==1||!isVal(node)||index<node.size())return false;
    return true;
}
};