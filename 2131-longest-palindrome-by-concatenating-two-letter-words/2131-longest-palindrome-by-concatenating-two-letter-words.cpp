class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        for(auto &w:words)mp[w]++;
        int ans=0;bool flag=false;
        for(auto &x:words){
            string w=x;
            reverse(x.begin(),x.end());
            if(w!=x && mp[x]>0 && mp[w]>0){
                ans+=4;
                mp[x]--;
                mp[w]--;
            }
            else if(x==w && mp[x]>1){
                ans+=4;
                mp[x]-=2;
            }
            else if(x==w && mp[x]>0 && !flag){
                ans+=2;
                mp[x]--;
                flag=true;
            }
        }
        return ans;
    }
};