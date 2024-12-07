class Solution {
public:
    bool isPossible(vector<int>&ranks,long long time,int cars){
        long long res=0;
        for(auto x:ranks){
            long long cn=sqrt(time/x);
            res+=cn;
        }
        return res>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long lt=1,rt=1e14;
        int n=ranks.size();
        long long ans=0;
        while(lt<=rt){
            long long t=lt+(rt-lt)/2;
            if(isPossible(ranks,t,cars)){
                ans=t;
                rt=t-1;
            }
            else
            lt=t+1;
        }
        return ans;
    }
};