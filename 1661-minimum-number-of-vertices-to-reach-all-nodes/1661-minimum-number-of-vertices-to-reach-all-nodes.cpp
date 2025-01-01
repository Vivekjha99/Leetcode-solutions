class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>g;
        vector<int>ind(n,0);
        for(auto e:edges){
            g[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }
        vector<int>nodes;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            if(ind[i]==0)nodes.push_back(i);
        }
        vector<int>res;
        queue<int>q;
        for(auto x:nodes){
            res.push_back(x);
            st.insert(x);
            q.push(x);
            while(!q.empty()){
                int curr=q.front();
                q.pop();
                st.insert(curr);
                for(auto ch:g[curr]){
                    if(st.find(ch)==st.end()){
                        q.push(ch);
                    }
                }
            }
            if(st.size()==n)break;
        }
        return res;
        
    }

};