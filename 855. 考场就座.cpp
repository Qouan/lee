class ExamRoom {set<int>positions;int maxSize;
public:
    ExamRoom(int N) {
        maxSize=N-1;
    }

    int seat() {
        if(positions.size()==0) {
            positions.insert(0);
            return 0;
        }
        auto it=*positions.begin();
        int maxd=0;
        int res=0;
        for(auto&po:positions)
        {
            if(po==it)continue;
            int dis=(po-it)/2;
            if(dis>maxd)
            {
                maxd=dis;
                res=(po+it)/2;
            }it=po;
        }
        if(!positions.count(0)&&*positions.begin()>=maxd)
        {
            maxd=*positions.begin();
            res=0;
        }
        if(!positions.count(maxSize)&&maxSize-it>maxd)
        {
            maxd=maxSize-it;
            res=maxSize;
        }
        positions.insert(res);
        return res;

    }

    void leave(int p) {
        if(positions.count(p))
        positions.erase(p);
    }
};


/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom obj = new ExamRoom(N);
 * int param_1 = obj.seat();
 * obj.leave(p);
 */
