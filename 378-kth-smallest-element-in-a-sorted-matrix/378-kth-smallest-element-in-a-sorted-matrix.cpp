class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int l=mat[0][0];
        int n=mat.size();
        if(n==1)return l;
        int h=mat[n-1][n-1];
        while(l<=h){
            int mid=(l+h)/2;
            int pos=0;
            //finding the pos in each row
            for(int i=0;i<n;i++){
                int idx=upper_bound(mat[i].begin(),mat[i].end(),mid)-mat[i].begin();
                // cout<<mat[i][idx]<<" "<<idx<<endl;
                pos+=idx;
            }
            if(pos<k){
                //as we are calculating upper bound
                l=mid+1;
            }
            else 
                h=mid-1;
        }
        return l;
    }
};