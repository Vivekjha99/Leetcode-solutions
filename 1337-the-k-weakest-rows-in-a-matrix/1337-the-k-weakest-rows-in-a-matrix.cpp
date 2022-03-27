class Solution {
public:
    bool compare(pair<int,int>&a,pair<int,int>&b){
        if(a.first<b.first)return true;
        else if(a.first==b.first)return a.first<b.first;
        else return false;
    }
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>pq;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j>0)mat[i][j]+=mat[i][j-1];
            }
            pq.push_back({mat[i][m-1],i});
        }
        sort(pq.begin(),pq.end(),[&](const pair<int,int>a,const pair<int,int>b){
            if(a.first==b.first)return a.second<b.second;
            else return a.first<b.first;
        });
        // for(auto x:pq){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        vector<int>ans;int idx=0;
        while(idx<k){
            ans.push_back(pq[idx++].second);
        }
        return ans;
        
    }
};