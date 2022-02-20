class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double,vector<double>,greater<double>>pq;
        int n=dist.size();
        for(int i=0;i<n;i++){
            pq.push(dist[i]*1.0/speed[i]);
        }
        int t=0;
        while(!pq.empty()&&t<pq.top()){
            
            t++;
            pq.pop();
        }
        return t;
    }
};