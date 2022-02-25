class Solution {
public:
    void solve(string &s,int idx,vector<string>&ans){
       ans.push_back(s);
        if(idx>=s.size())return;
        for(int i=idx;i<s.size();i++){
            if(isalpha(s[i])){
                s[i]^=32;
                solve(s,i+1,ans);
                s[i]^=32;
            }
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        solve(s,0,ans);
        return ans;
    }
};