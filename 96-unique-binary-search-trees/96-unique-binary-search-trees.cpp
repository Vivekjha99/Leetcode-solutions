class Solution {
public:
    long long catalan(int n,int k){
        if(k>(n-k))
            k=n-k;
        long long res=1;
        for(int i=0;i<k;i++){
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }
    int numTrees(int n) {
        long long res=catalan(2*n,n);
        res/=(n+1);
        return (int)res;
    }
};