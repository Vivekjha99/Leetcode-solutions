class Solution {
public:
    vector<int>par;
    int find(int x){
        if(par[x]==x)return x;
        return par[x]=find(par[x]);
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return 0;
        int groups=n;
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(grid[i][j]){
                    int p1=find(i);
                    int p2=find(j);
                    if(p1!=p2){
                        par[p2]=p1;
                        groups--;
                    }
                }
            }
        }
        return groups;
        
    }
};