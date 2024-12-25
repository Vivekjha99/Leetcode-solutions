class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1)return {0};
        unordered_map<int,vector<int>>g;
        vector<int>ind(n,0);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            ind[e[1]]++;ind[e[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(ind[i]==1)q.push(i);
        }
        int remainingNodes=n;
        while(remainingNodes>2){
            int sz=q.size();
            remainingNodes-=sz;
            for(int i=0;i<sz;i++){
                int curr=q.front();
                q.pop();
                for(auto ch:g[curr]){
                    if(--ind[ch]==1)q.push(ch);
                }
            }
        }
        vector<int>res;
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};