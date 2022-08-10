class Solution {
public:
double bfs(unordered_map<string,vector<pair<string,double>>>&g,string &src,string &dest){
        if(src==dest){
            return 1.0;
        }
        unordered_set<string>vis; 
        queue<pair<string,double>>q;
        q.push({src,1.0});
        vis.insert(src);
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            for(auto x:g[p.first]){
                if(vis.find(x.first)==vis.end()){
                    if(x.first==dest)
                        return p.second*x.second;
                    vis.insert(x.first);
                    q.push({x.first,p.second*x.second});
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>g;
        for(int i=0;i<e.size();i++){
            g[e[i][0]].push_back({e[i][1],values[i]});
            g[e[i][1]].push_back({e[i][0],1.0/values[i]});
        }
        vector<double>ans;
        for(int i=0;i<queries.size();i++){
            string src=queries[i][0];
            string dest=queries[i][1];
            if(g.find(src)==g.end() && g.find(dest)==g.end()){
                ans.push_back(-1.0);
            }
            else{
                double res=bfs(g,src,dest);
                ans.push_back(res);
            }   
        }
        return ans;
    }
};