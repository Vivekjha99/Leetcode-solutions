class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int colIdx=0,dir=1;
        vector<int>res;
        for(int i=0;i<m;i++){
            while(colIdx>=0 && colIdx<n){
                res.push_back(grid[i][colIdx]);
                colIdx+=(2*dir);
            }
            cout<<colIdx<<endl;
            dir*=-1;
            if(dir>0){
                colIdx+=1;
            }
            else{
                colIdx=n-1-(colIdx)%n;
            }
        }
        return res;
    }
};