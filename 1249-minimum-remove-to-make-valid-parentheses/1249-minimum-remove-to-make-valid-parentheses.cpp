class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans="";
        int n=s.size();
        int a=0;
        unordered_map<int,int>mp;
        stack<int>st;
        for(int i=0;i<n;i++){
            mp[i]=1;
            if(s[i]==')'){
                if(st.empty())mp[i]=0;
                else st.pop();
            }
            else if(s[i]=='(')st.push(i);
        }
        while(!st.empty()){
            mp[st.top()]=0;
            st.pop();
        }
        for(int i=0;i<n;i++){
           
            if(mp[i])ans.push_back(s[i]);
        }
        return ans;
        
    }
};