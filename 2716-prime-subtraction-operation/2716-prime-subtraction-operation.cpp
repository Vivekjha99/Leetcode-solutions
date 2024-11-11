class Solution {
public:
    void sieve(vector<int>&primes){
        vector<bool>sieves(1001,true);
        sieves[1]=false;
        sieves[0]=false;
        for(int i=2;i*i<=1000;i++){
            if(sieves[i]){
                for(int j=i*i;j<=1000;j+=i){
                    sieves[j]=false;
                }
            }
        }
        for(int i=0;i<=1000;i++)
        if(sieves[i])primes.push_back(i);
    }
    bool primeSubOperation(vector<int>& nums) {
        int n=nums.size();
        vector<int>primes;
        sieve(primes);
        int prev=nums[n-1];
        bool flag=false;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<prev){
                prev=nums[i];
                continue;
            }
            flag=true;
            for(int j=0;j<primes.size()&& primes[j]<nums[i];j++){
                if(nums[i]-primes[j]<prev){
                    prev=nums[i]-primes[j];
                    flag=false;
                    break;
                }
            }
            if(flag)break;
        }
        return !flag;
    }
};