class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        sort(points.begin(),points.end(),[](pair<int, int>a,pair<int, int> b)
    { return a.first<b.first;});
    int start=-999999,end;
    int count=0;
    for(int i=0;i<points.size();++i)
    {
        if(start==-999999)
        {
            start=points[i].first;
            end=points[i].second;
            ++count;
        }
        else
        {
            if(end>=points[i].first)
            {
                start=points[i].first;
                end=min(end,points[i].second);
            }
            else
            {
                start=-999999;
                --i;
            }
        }
        //cout<<start<<" "<<end<<endl;
    }
    return count;
    }
};
