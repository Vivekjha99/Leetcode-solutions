class Solution {
public:
void euler(unordered_map<string,vector<string>>&g,vector<string>&ans,string curr){
    while(!g[curr].empty()){
        string v=g[curr].back();
        g[curr].pop_back();
        euler(g,ans,v);
    }
    ans.push_back(curr);
}
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>g;
        for(auto &t:tickets){
            g[t[0]].push_back(t[1]);
        }
        for(auto &[p,d]:g){
            sort(d.rbegin(),d.rend());
        }
        vector<string>ans;
        euler(g,ans,"JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
};