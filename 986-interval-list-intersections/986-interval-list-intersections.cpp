class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int m=B.size();
        int i=0,j=0;
        vector<vector<int>>ans;
        while(i<n && j<m){
            int l=max(A[i][0],B[j][0]);
            int r=min(A[i][1],B[j][1]);
            if(l<=r)ans.push_back({l,r});
            if(A[i][1]<B[j][1])i++;
            else j++;
        }
        return ans;
    }
};