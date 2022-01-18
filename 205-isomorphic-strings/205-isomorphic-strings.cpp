class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        if(n1!=n2)return false;
        unordered_map<char,char>mp;
        set<char>st;
        for(int i=0;i<n1;i++){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])return false;
            }
            else{
                if(st.count(t[i]))return false;
                mp[s[i]]=t[i];
                st.insert(t[i]);
            }
        }
        return true;
    }
};