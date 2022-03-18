class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=i;
        }
        stack<char>st;bool vis[26]={false};
        for(int i=0;i<s.size();i++){
            if(vis[s[i]-'a'])continue;
            else{
            if(!st.empty() && st.top()>s[i]){
                while(!st.empty() && st.top()>s[i]){
                    if(mp[st.top()]>i){
                        vis[st.top()-'a']=false;
                        st.pop();
                    }
                    else break;
                }
            }
            st.push(s[i]);
                vis[s[i]-'a']=true;
            }
        }
        string ans="";
        while(!st.empty()){
           
            ans.push_back(st.top());
            
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};