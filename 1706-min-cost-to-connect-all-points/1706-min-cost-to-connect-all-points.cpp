class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>vis(n,false);
        pq.push({0,0});//dist,index of point
        int minCost=0;
        while(!pq.empty()){
            auto p=pq.top();
            pq.pop();
            int wt=p.first;
            int idx=p.second;
            if(vis[idx])continue;
            vis[idx]=true;
            minCost+=wt;
            for(int nIdx=0;nIdx<n;nIdx++){
                if(!vis[nIdx]){
                    int nWt=abs(points[nIdx][0]-points[idx][0])+abs(points[idx][1]-points[nIdx][1]);
                    pq.push({nWt,nIdx});
                }
            }
        }
        return minCost;
    }
};