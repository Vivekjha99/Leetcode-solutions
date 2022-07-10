class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        vector<int>dp={1,0,1};
        for(auto x:obstacles){
            if(x>0)dp[x-1]=1e6;
            for(int i=0;i<3;i++){
                if(i!=x-1){
                    dp[i]=min({dp[i],1+dp[(i+1)%3],1+dp[(i+2)%3]});
                }
            }
        }
        return min({dp[0],dp[1],dp[2]});
    }
};