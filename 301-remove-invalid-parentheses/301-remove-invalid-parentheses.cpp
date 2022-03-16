class Solution {
public:
    bool isValid(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')cnt++;
            else if(s[i]==')')cnt--;
            if(cnt<0)return false;
        }
        return cnt==0;
    }
    void bfs(string &s,vector<string>&ans){
        if(s=="")return;
        bool found=false;
        unordered_set<string>vis;
        queue<string>q;
        q.push(s);
        while(!q.empty()){
            string st=q.front();
            q.pop();
            if(isValid(st)){
                ans.push_back(st);
                found=true;
            }
            if(found)continue;
            for(int i=0;i<st.size();i++){
                if(st[i]!='(' && st[i]!=')')continue;
                string ns=st.substr(0,i)+st.substr(i+1);
                if(vis.count(ns)==0){
                    q.push(ns);
                    vis.insert(ns);
            }
        }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string>ans;
        bfs(s,ans);
        return ans;
    }
};