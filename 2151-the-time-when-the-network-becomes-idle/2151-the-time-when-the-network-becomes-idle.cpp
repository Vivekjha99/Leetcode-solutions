class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n=patience.size();
        unordered_map<int,vector<int>>g;
        for(auto &e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        int inf=1e9;
        vector<int>dist(n,inf);
        dist[0]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int par=q.front();
            q.pop();
            for(auto ch:g[par]){
                if(dist[ch]==inf){
                    dist[ch]=dist[par]+1;
                    q.push(ch);
                }
            }
        }
        int res=0;
        for(int i=1;i<n;i++){
          int extraSignals=(dist[i]*2-1)/patience[i];
          int lastSignalSentTime=extraSignals*patience[i];
          int lastSignalRecieved=lastSignalSentTime+dist[i]*2;
          res=max(res,lastSignalRecieved);//till this time last signal will end
        }
        return res+1 ;
    }
};