class Solution {
public:
    string search(string&s,int start,int end) {
    int len = static_cast<int>(s.size());
    string res = "";
    while(start<=end){
    int i = start;
    for (; i <=end && s[i] != '['; ++i);

    int count=1;
    for (int k = start; k < i; ++k) {
        if (!isdigit(s[k]))res += s[k];
        else {
            int j = k + 1;
            while (j < i && isdigit(s[j]))++j;
            count = atoi(s.substr(k, j - k).c_str());
            if (j >= i)break;
            k = j;
            j = k + 1;
            while (j < i && !isdigit(s[j]))++j;
            string temp = s.substr(k, j - k);
            while (count--)
                res += temp;
            k = j - 1;
        }
    }
    int left = 0, right = 0;
    int j = i;
    for (; j <= end; ++j) {
        if (s[j] == '[')++left;
        if (s[j] == ']')++right;
        if (left == right)break;
    }
    string temp;
    if (left == 1) {
        temp = s.substr(i + 1, j - i - 1);

    } else {
        temp = search(s, i + 1, j - 1);
    }while (count--)res += temp;
    start = j + 1;
}
    return res;
}
string decodeString(string s)
{
    return search(s,0,s.size()-1);
}
};