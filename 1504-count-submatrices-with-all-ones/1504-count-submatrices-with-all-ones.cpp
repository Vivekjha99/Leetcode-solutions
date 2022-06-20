class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        //first we will calculate for each row
        for(int i=0;i<n;i++){
            for(int j=m-2;j>=0;j--){
                if(mat[i][j]){
                    mat[i][j]+=mat[i][j+1];
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                 int min_width=mat[i][j];
                for(int d=i;d<n;d++){
                    if(mat[d][j]==0)break;
                    min_width=min(min_width,mat[d][j]);
                   ans+=min_width; 
                }
            }
        }
        return ans;
    }
};