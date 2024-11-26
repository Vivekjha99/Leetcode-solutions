class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<edges.size();i++){
           vis[edges[i][1]]++;
        }
        int res=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                res=i;
            }
        }
        return cnt==1?res:-1;
    }
};