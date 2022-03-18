class Solution {
public:
    string smallestSubsequence(string s) {
        string ans="";
        int n=s.size();
        stack<char>st;
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)mp[s[i]]=i;
        vector<bool>vis(26,false);
        for(int i=0;i<n;i++){
            if(vis[s[i]-'a'])continue;
            while(!st.empty() && st.top()>s[i] && mp[st.top()]>i){
                vis[st.top()-'a']=false;
                st.pop();
            }
            vis[s[i]-'a']=true;
            st.push(s[i]);
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};