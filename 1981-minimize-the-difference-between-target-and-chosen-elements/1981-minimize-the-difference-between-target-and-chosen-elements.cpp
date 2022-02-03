class Solution {
public:
    int n,m;
    int dp[72][5000];
    int solve(vector<vector<int>>&mat,int idx,int sum,int &target){
        if(idx==n)return abs(sum-target);
        if(dp[idx][sum]!=-1)return dp[idx][sum];
        int mindiff=INT_MAX;
        for(int i=0;i<m;i++){
            mindiff=min(mindiff,solve(mat,idx+1,sum+mat[idx][i],target));
        }
        return dp[idx][sum]=mindiff;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n=mat.size();
        m=mat[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(mat,0,0,target);
    }
};