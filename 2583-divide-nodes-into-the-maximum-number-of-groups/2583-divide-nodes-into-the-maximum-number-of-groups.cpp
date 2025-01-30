class Solution {
public:
bool isBipartite(int node,int col,unordered_map<int,vector<int>>&g,vector<int>&colors,vector<int>&comps){
    colors[node]=col;
    comps.push_back(node);
    for(auto &child:g[node]){
        if(colors[child]==col)return false;
        if(colors[child]==-1 && isBipartite(child,1-col,g,colors,comps)==false)return false;
    }
    return true;
}
//bfs from all nodes to get the max depth possible in each comp
    int findMaxDepth(vector<int>&comps,int n,unordered_map<int,vector<int>>&g){
        int maxDepth=0;
        for(int node: comps){
            vector<int>depth(n,-1);
            queue<int>q;
            q.push(node);
            depth[node]=0;
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                for(int ch:g[curr]){
                    if(depth[ch]==-1){
                        depth[ch]=depth[curr]+1;
                        q.push(ch);
                        maxDepth=max(maxDepth,depth[ch]);
                    }
                }
            }
        }
        return maxDepth+1;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int>colors(n,-1);
        unordered_map<int,vector<int>>g;
        for(auto &e:edges){
            g[e[0]-1].push_back(e[1]-1);
            g[e[1]-1].push_back(e[0]-1);
        }
        vector<vector<int>>comps;
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                vector<int>c;
                if(!isBipartite(i,0,g,colors,c))return -1;
                comps.push_back(c);
            }
        }
        //now we will find the max depth in each comp
        int res=0;
        for(auto &c:comps){
            res+=findMaxDepth(c,n,g);
        }
        return res;
    }
};