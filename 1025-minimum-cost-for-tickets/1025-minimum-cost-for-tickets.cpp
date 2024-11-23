class Solution {
public:
    // int solve(vector<int>&days,int id,vector<int>&costs,vector<int>&dp){
    //     int n=days.size();
    //     //sending 0 as the user has completed his journey , the requirement
    //     if(id>=days.size())return 0;
    //     if(dp[id]!=INT_MAX)return dp[id];
    //     //at every purchase point i have to think in one of these 3 passes.
    //     int c1=costs[0]+solve(days,id+1,costs,dp);
    //     int i=0;
    //     for(i=id;i<n && days[i]<days[id]+7;i++);
    //     int c2=costs[1]+solve(days,i,costs,dp);
    //     for(i=id;i<n && days[i]<days[id]+30;i++);
    //     int c3=costs[2]+solve(days,i,costs,dp);
    //     return dp[id]=min({c1,c2,c3});
    // }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // vector<int>dp(366,INT_MAX);
        // return solve(days,0,costs,dp);
        vector<int>dp(days.back()+1);
        unordered_set<int>st(days.begin(),days.end());
        //if the ith day is not in the travel day no need to take ticket
        for(int i=1;i<=days.back();i++){
            if(st.find(i)==st.end()){
                dp[i]=dp[i-1];
                continue;
            }
            dp[i]=costs[0]+dp[i-1];
            dp[i]=min(dp[i],costs[1]+dp[max(0,i-7)]);
            dp[i]=min(dp[i],costs[2]+dp[max(0,i-30)]);
        }
        return dp[days.back()];
    }
};