class Solution {
public:
    int uniquePaths(int m, int n) {
        int x=m+n-2;
        int y=min(n,m)-1;
        double res=1;
        for(int i=1;i<=y;i++){
            // cout<<x<<" "<<i<<endl;
            res=res*x;
            res/=i;
            x--;
            
        }
        return (int)res;
    }
};