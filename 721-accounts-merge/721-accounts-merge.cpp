class Solution {
public:
    unordered_map<string,vector<string>>g;
    unordered_set<string>vis;
    void dfs(string email,vector<string>&res){
        vis.insert(email);
        res.push_back(email);
        for(auto x:g[email]){
            if(vis.find(x)==vis.end())
                dfs(x,res);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>>ans;
        int n=accounts.size();
        for(int i=0;i<n;i++){
            string femail=accounts[i][1];
            for(int j=2;j<accounts[i].size();j++){
                string email=accounts[i][j];
                g[femail].push_back(email);
                g[email].push_back(femail);
            }
        }
        for(int i=0;i<n;i++){
            string accname=accounts[i][0];
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(vis.find(email)==vis.end()){
                    vector<string>res;
                    dfs(email,res);
                    sort(res.begin(),res.end());
                    res.insert(res.begin(),accname);
                    ans.push_back(res);
                }
            }
        }
        return ans;
    }
};