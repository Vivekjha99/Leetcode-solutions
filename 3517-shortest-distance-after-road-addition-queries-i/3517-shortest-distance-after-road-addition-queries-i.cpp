class Solution {
public:
typedef pair<int,int> pii;
    int calcDist(map<int,vector<int>>&mp,int n){
        queue<pii>q;
        unordered_set<int>vis;
        vis.insert(0);
        q.push(make_pair(0,0));
        while(!q.empty()){
            pii p=q.front();
            q.pop();
            int curr=p.first;
            int d=p.second;
            if(curr==n-1)return d;
            for(auto c:mp[curr]){
                if(vis.find(c)==vis.end()){
                    q.push(make_pair(c,d+1));
                    vis.insert(c);
                }
            }
        }
        return -1;
        
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        map<int,vector<int>>mp;
        for(int i=0;i<n-1;i++){
            mp[i].push_back(i+1);
        }
        vector<int>res;
        for(auto q:queries){
            mp[q[0]].push_back(q[1]);
            res.push_back(calcDist(mp,n));
        }
        return res;
    }
};