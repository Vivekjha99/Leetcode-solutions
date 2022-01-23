class Solution {
public:
    int sieve(int n){
        vector<int>v(n,1);
        v[0]=0;
        v[1]=0;
        int cnt=0;
        for(int i=0;i*i<n;i++){
            if(v[i]){
                for(long long j=i*i;j<n;j+=i)
                    v[j]=0;
            }
        }
        return accumulate(v.begin(),v.end(),0);
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        return sieve(n);
    }
};