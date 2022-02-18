class Solution {
public:
    int balancedString(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        int st=0;
        int ans=n+1;
        int x=n/4;
        for(int i=0;i<n;i++){
            mp[s[i]]--;
            while(mp['Q']<=x && mp['W']<=x && mp['E']<=x && mp['R']<=x){
                mp[s[st]]++;
                ans=min(ans,i-st+1);
                st++;
                if(st>=n)break;
            }
        }
        return ans;
    }
};