class Solution {
public:
    int findSqrt(int n){
        int l=1,r=n;long long ans=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long res=mid*mid;
            if(res==n){
                return mid;
            }
            if(mid*mid<n){
                l=mid+1;
                ans=mid;
            }
            else
            r=mid-1;
        }
        return ans;
    }
    int bulbSwitch(int n) {
        if(n==0)return 0;
        return findSqrt(n);
    }
};