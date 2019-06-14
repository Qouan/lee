#include <algorithm>
==================1====================
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
unsigned long str2byte(string word){
    string str(26,'0');
    for(auto w:word){
        str[w-'a']='1';
    }
    bitset<26>bs(str);
    return bs.to_ulong();
}
int maxProduct(vector<string>& words){
    vector<unsigned long>vec;
    for(auto word:words){
        vec.push_back(str2byte(word));
    }
    int res=0;
    for(int i=0;i<words.size();++i){
        for(int j=i+1;j<words.size();++j){
            if((vec[i]&vec[j])==0){
                int newProduct=words[i].size()*words[j].size();
                res=newProduct>res?newProduct:res;
            }
        }
    }
    return res;
}
int main()
{
    vector<string>a={"a","aa","aaa","aaaa"};
    cout<<maxProduct(a);

}