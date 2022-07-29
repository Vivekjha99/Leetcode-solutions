class Solution {
public:
    bool check(string w,string p){
        unordered_map<char,char>mp1,mp2;
        for(int i=0;i<p.size();i++){
            if(mp1.count(p[i]) && mp1[p[i]]!=w[i] || mp2.count(w[i]) && mp2[w[i]]!=p[i])return false;
            mp1[p[i]]=w[i];
            mp2[w[i]]=p[i];
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pat) {
        vector<string>ans;
        unordered_map<char,char>mp1,mp2;
        for(auto w:words){
            if(check(w,pat))ans.push_back(w);
        }
        return ans;
    }
};