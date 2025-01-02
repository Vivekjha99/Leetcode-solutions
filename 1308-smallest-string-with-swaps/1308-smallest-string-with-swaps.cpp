class Solution {
public:
void dfs(string &s,int i,string &res,vector<int>&indices,vector<bool>&vis,unordered_map<int,vector<int>>&g){
    vis[i]=true;
    indices.push_back(i);
    res.push_back(s[i]);
    for(auto ch:g[i]){
        if(!vis[ch])dfs(s,ch,res,indices,vis,g);
    }
}
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>>g;
        int n=s.size();
        for(auto p:pairs){
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }
        vector<bool>vis(n,false);
        for(int i=0;i<s.size();i++){
            if(!vis[i]){
                vector<int>indicesVis;
                string res="";
                dfs(s,i,res,indicesVis,vis,g);
                sort(indicesVis.begin(),indicesVis.end());
                sort(res.begin(),res.end());
                for(int i=0;i<indicesVis.size();i++){
                    s[indicesVis[i]]=res[i];
                }
            }
        }
        return s;
    }
};