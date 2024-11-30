class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //current element and bitstate
        queue<pair<int,int>>q;
        int n=graph.size();
        if(n==1)return 0;
        int finalState=(1<<n)-1;
        //as we have to check from all the nodes
        for(int i=0;i<n;i++){
            q.push({i,(1<<i)});
        }
        //this will prevent the endless cycle
        vector<vector<int>>vis(n,vector<int>(finalState+1,0));
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            steps++;
            for(int i=0;i<sz;i++){
                auto p=q.front();
                q.pop();
                int node=p.first;
                int mask=p.second;
                for(auto nb:graph[p.first]){
                    int newMask=mask|1<<nb;
                    if(vis[nb][newMask])continue;
                    vis[nb][newMask]=1;
                    if(newMask==finalState)return steps;
                    q.push({nb,newMask});
                }
                }
                
            }
        return -1;
    }
};