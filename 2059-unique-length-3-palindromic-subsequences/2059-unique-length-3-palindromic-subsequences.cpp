class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])==mp.end()){
                mp[s[i]].first=i;
                mp[s[i]].second=-1;
            }
            else mp[s[i]].second=i;
        }
        int res=0;
        for(auto [c,p]:mp){
            if(p.second==-1)continue;
            unordered_set<int>st;
            for(int i=p.first+1;i<p.second;i++)st.insert(s[i]);
            res+=st.size();
        }
        return res;
    }
};