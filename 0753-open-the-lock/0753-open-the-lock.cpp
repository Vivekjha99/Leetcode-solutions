class Solution {
public:
vector<string > getChilds(string s){
    vector<string>res;
    for(int i=0;i<4;i++){
        for(int j=-1;j<=1;j+=2){
            string t=s;
            t[i]=(t[i]-'0'+j+10)%10+'0';
            res.push_back(t);
        }
    }
    return res;
}
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>st;
        for(auto x:deadends){
            st.insert(x);
        }
        if(st.count("0000"))return -1;
        queue<string>q;
        int steps=0;
        q.push("0000");
        st.insert("0000");
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
            string curr=q.front();
            q.pop();
            if(curr==target)return steps;
            vector<string> childs=getChilds(curr);
            for(auto c:childs){
                if(st.count(c))continue;
                st.insert(c);
                q.push(c);
            }
        }
        steps++;
        }
        return -1;
    }
};