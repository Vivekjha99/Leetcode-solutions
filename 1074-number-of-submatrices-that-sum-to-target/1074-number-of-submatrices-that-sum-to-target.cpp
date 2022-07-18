class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        //cal row sum
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int colstart=0;colstart<m;colstart++){
            for(int colend=colstart;colend<m;colend++){
                int sum=0;
                mp={{0,1}};
                // cout<<mp.size()<<endl;
                //everytime we are checking a new segment
                for(int row=0;row<n;row++){
                    sum+=mat[row][colend]-(colstart?mat[row][colstart-1]:0);
                    ans+=mp[sum-k];
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};