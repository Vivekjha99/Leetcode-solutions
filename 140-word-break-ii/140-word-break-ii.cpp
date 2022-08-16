class Solution {
public:
    void solve(int idx,string s,string curr,unordered_set<string>st,vector<string>&res){
        if(idx==s.size()){
            curr.pop_back();
            res.push_back(curr);
        }
        string str="";
        for(int i=idx;i<s.size();i++){
            str.push_back(s[i]);
            if(st.count(str)){
                solve(i+1,s,curr+str+" ",st,res);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        for(auto x:wordDict){
            st.insert(x);
        }
        string str="";
        vector<string>res;
        solve(0,s,str,st,res);
        return res;
    }
};