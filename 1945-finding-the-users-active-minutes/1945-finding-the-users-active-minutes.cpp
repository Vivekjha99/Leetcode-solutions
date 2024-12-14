class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,unordered_set<int>>mp;
        for(auto l:logs){
            mp[l[0]].insert(l[1]);
        }
        vector<int>res(k);
        for(auto x:mp){
            res[x.second.size()-1]++;
        }
        return res;
    }
};