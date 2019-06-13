-------------------------------  #1  -------------------------------
class Solution {
     vector<int>button;
    vector<int>list={1,2,4,8,16,32};
    vector<vector<int> >top_grid={{0,-1,-1,-1,-1,-1},{1,2,4,8,-1,-1},{3,5,6,9,10,-1},{7,11,-1,-1,-1,-1}};
public:
   
void combination(int goal_times,int left_times,int index,int num){
    if(goal_times>6||goal_times<0)return;
    if(left_times==0&&num<60)button.push_back(num);
    for(int i=index;i<6;++i){
        num+=list[i];
        combination( goal_times,left_times-1,i+1,num);
        num-=list[i];
    }
}

vector<string> readBinaryWatch(int num) {
    vector<string>res;
    for(int i=0;i<=3&&i<=num;++i){
        vector<int>top=top_grid[i];
        combination(num-i,num-i,0,0);
        vector<int>buttom=button;
        sort(buttom.begin(),buttom.end());
        button.clear();
        for(auto&a:top){
            for(auto&b:buttom){
                if(a==-1||b==-1)break;
                res.push_back(to_string(a)+":"+(b<10?"0":"")+to_string(b));
            }
        }
    }
    return res;
}
};


-------------------------------  #2  -------------------------------
class Solution {
public:
    int n_digit(int num){
    int res=0;
    while(num){
        if(num&0x1)++res;
        num>>=1;
    }
    return res;
}
vector<string> readBinaryWatch(int num){
    vector<string>st;
    for(int hr=0;hr<12;++hr){
        for(int mit=0;mit<60;++mit) {
            if (n_digit(hr) + n_digit(mit) == num) {
                st.push_back(to_string(hr) + ":" + (mit < 10 ? "0" : "") + to_string(mit));
            }
        }
    }
        return st;
}
};