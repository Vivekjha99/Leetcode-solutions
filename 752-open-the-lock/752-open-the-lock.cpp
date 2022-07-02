class Solution {
public:
    vector<string> solve(string s){
        vector<string>res;
        for(int i=0;i<4;i++){
            for(int j=-1;j<=1;j+=2){
                string temp=s;
                temp[i]=(temp[i]-'0'+j+10)%10+'0';
                res.push_back(temp);
            }
        }
        return res;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st;
        for(auto &x:deadends)st.insert(x);
        if(st.count("0000"))return -1;
        queue<string>q;
        q.push("0000");
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                string s=q.front();
                q.pop();
                if(s.compare(target)==0)return steps;
                vector<string>neig=solve(s);
                for(auto w:neig){
                    if(st.count(w))continue;
                    st.insert(w);
                    q.push(w);
                }
            }
             steps++;
        }
        return -1;
    }
};