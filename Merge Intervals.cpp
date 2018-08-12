#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

  struct Interval {
      int start;
     int end;
      Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

  bool cmp(Interval a,Interval b)
      {
          return (a.start<b.start);
      }
  vector<Interval> merge(vector<Interval>& intervals) {
         if(intervals.empty()) return {};
         sort(intervals.begin(),intervals.end(),cmp);
          for(int i=0;i<intervals.size()-1;){
             if(intervals[i].end>=intervals[i+1].end){intervals.erase(intervals.begin()+i+1);continue;}
             if(intervals[i].end>=intervals[i+1].start){
                 intervals[i].end=intervals[i+1].end;
               intervals.erase(intervals.begin()+i+1);
               continue;
             }
              i++;
           }
         return intervals;
     }
int main()
{
      Interval a(1,4);
      Interval b(0,4);
      vector<Interval> intervals;
      intervals.push_back(a);
      intervals.push_back(b);

}
