class Solution {
public:
    bool check(int val,int m,int n,int k){
        int res=0;
        for(int i=1;i<=m;i++){
            res+=min(val/i,n);
        }
        return res>=k;
    }
    int findKthNumber(int m, int n, int k) {
        int s=1,e=m*n;
        while(s<e){
            int mid=(s+e)/2;
            if(check(mid,m,n,k))e=mid;
            else s=mid+1;
        }
        return s;
    }
};