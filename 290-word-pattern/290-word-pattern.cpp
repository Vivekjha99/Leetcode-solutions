class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>res;
        string ns="";
        for(auto x:s){
            if(x==' '){
                res.push_back(ns);
                ns="";
            }
            else
                ns+=x;
        }
        set<string>st;
        res.push_back(ns);
        if(pattern.size()!=res.size())return false;              unordered_map<char,string>mp;
        for(int i=0;i<pattern.length();i++){
            if(mp.find(pattern[i])!=mp.end()){
        
                if(mp[pattern[i]]!=res[i])return false;
            }
            else{
                if(st.count(res[i])>0){
                    //string already mapped
                    return false;
                }
                mp[pattern[i]]=res[i];
                st.insert(res[i]);
            }
        }
        return true;
    }
};