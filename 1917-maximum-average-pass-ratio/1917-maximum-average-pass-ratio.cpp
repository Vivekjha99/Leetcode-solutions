#define pdd pair<double,pair<int,int>>
class compare{
    public:
        bool operator()(pdd a ,pdd b){
            double avg1=(1.0*(a.second.first+1)/(a.second.second+1));
            double avg2=(1.0*(b.second.first+1)/(b.second.second+1));
            double diff1=avg1-a.first;
            double diff2=avg2-b.first;
            if(diff1>=diff2)return false;
            else return true;
        }
};

class Solution {

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pdd,vector<pdd>,compare>pq;
        double totAvg=0.0;
        for(auto c:classes){
            double avg=(1.0*c[0]/c[1]);
            pq.push({avg,{c[0],c[1]}});
        }
        while(extraStudents>0){
            auto curr=pq.top();
            pq.pop();
            double currAvg=curr.first;
            int pass=curr.second.first+1;
            int total=curr.second.second+1;
            double newAvg=(1.0*(pass)/(total));
            extraStudents--;
            pq.push({newAvg,{pass,total}});
        }
        while(!pq.empty()){
            totAvg+=pq.top().first;
            pq.pop();
        }
        totAvg/=n;
        return totAvg;
    }
};