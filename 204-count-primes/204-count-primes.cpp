class Solution {
public:
    int sieve(int n){
        vector<int>v(n+1,1);
        v[0]=0;
        v[1]=0;
        int cnt=0;
        for(int i=2;i<n;i++){
            if(v[i]){
                cnt++;
                for(long long j=i;j<n;j+=i)
                    v[j]=0;
            }
        }
        return cnt;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        return sieve(n);
    }
};