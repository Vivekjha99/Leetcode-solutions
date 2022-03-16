class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(auto x:strs){
            string st=x;
            sort(st.begin(),st.end());
            mp[st].push_back(x);
        }
        vector<vector<string>>ans;
        for(auto [s,v]:mp){
            ans.push_back(v);
        }
        return ans;
    }
};