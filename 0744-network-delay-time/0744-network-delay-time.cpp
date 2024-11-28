class Solution {
public:
typedef pair<int, int> pii;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pii>>g;
        for(auto t:times){
            g[t[0]].emplace_back(t[1],t[2]);
        }
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.push({0,k});
        vector<bool>vis(n+1,false);
        int res=0;
        int N=n;
        int inf=1e9;
        vector<int>dist(n+1,inf);
        dist[k]=0;
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int par=curr.second;
            res=curr.first;
            if(vis[par])continue;
            vis[par]=true;
            N--;
            if(N==0)return res;
            for(auto ch:g[par]){
            if(dist[ch.first]>dist[par]+ch.second){
                dist[ch.first]=dist[par]+ch.second;
                pq.push({dist[ch.first],ch.first});
            }
        }
    }
    return N==0?res:-1;
    }
};