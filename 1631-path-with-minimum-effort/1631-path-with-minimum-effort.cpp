class Solution {
    private:
    int n;
    int m;
    vector<vector<bool>>visited;
public:
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    bool isvalid(int x,int y){
        return x < n and x >= 0 and y < m and y >= 0;
    }
    bool solve(vector<vector<int>>&arr,int i,int j,int val){
        visited[i][j]=true;
        if(i==n-1 && j==m-1)return true;
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(isvalid(x,y) && !visited[x][y] && abs(arr[x][y]-arr[i][j])<=val)
                if(solve(arr,x,y,val))return true;
        }
        return false;
    }
    bool ispossible(vector<vector<int>>&arr,int k){
       visited.assign(n,vector<bool> (m, false));
        return solve(arr,0,0,k);
    }
    int minimumEffortPath(vector<vector<int>>& arr) {
        n=arr.size();
        m=arr[0].size();
        int r=1e6;
        int l=0;
        int ans=0;
        while(l<r){
            int mid=l+(r-l)/2;
            if(ispossible(arr,mid)){
                ans=mid;
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};