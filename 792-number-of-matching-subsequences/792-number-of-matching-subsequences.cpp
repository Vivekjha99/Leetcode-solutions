class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char,vector<int>>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int ans=0;
        for(auto x:words){
            int curr=-1;
            bool flag=true;
            for(int i=0;i<x.size();i++){
                auto it=upper_bound(mp[x[i]].begin(),mp[x[i]].end(),curr);
                if(it==mp[x[i]].end()){
                    flag=false;
                    break;
                }
                else curr=*it;
            }
            if(flag)ans++;
        }
        return ans;
    }
};