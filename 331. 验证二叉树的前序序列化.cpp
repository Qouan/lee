#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;
int isvalid(vector<string>&data,int pos)
{
    if(pos>=data.size())return -1;
    if(data[pos]=="#")
        return pos+1;
    int rightStart=isvalid(data,pos+1);
    if(rightStart==data.size())return -1;
    return isvalid(data,rightStart);
}
bool isValidSerialization(string preorder)
{
    vector<string>data;
    int start=0,i;
    while(start<preorder.size()) {
        for (i = start; i<preorder.size()&&preorder[i] != ','; ++i);
        data.push_back(preorder.substr(start, i - start));
        start = i + 1;
    }
    return isvalid(data,0)==data.size();
}
int main()
{
    cout<<isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#");
}
