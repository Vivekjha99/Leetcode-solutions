class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int smallest=INT_MAX;
        long long sum=0;
        int n=matrix.size();int negs=0;
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]<0)negs++;
                sum+=abs(matrix[i][j]);
                smallest=min(smallest,abs(matrix[i][j]));
            }
        }
        if(negs%2==0)return sum;
        else return sum-2*smallest;

    }
};