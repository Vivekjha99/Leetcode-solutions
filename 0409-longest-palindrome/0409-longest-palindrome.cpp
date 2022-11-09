class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mp;
        for(auto x:s)mp[x]++;
        int ans=0;
        bool flag=false;
        for(auto [c,f]:mp){
            if(f>0){
                ans+=f-f%2;
                if(f%2 && !flag){
                ans++;
                flag=true;
                }
            }
        }
        return ans;
    }
};