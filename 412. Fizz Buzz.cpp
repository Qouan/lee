class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>res;
    for(int i=1;i<=n;++i){
        string toBePush;
        if(i%3==0){
            if(i%5==0)
                toBePush= "FizzBuzz";
            else
                toBePush="Fizz";
        }
        else if(i%5==0)
            toBePush="Buzz";
        else toBePush=to_string(i);
        res.push_back(toBePush);
    }
    return res;
    }
};