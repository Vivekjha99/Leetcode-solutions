class Solution {
public:
    int findMinPrice(vector<int>&days,int currDay,vector<int>&costs,vector<int>&dp){
        if(currDay>=days.size())return 0;
        if(dp[currDay]!=-1)return dp[currDay];
        int nIdx1=lower_bound(days.begin(),days.end(),days[currDay]+1)-days.begin();
        int nIdx2=lower_bound(days.begin(),days.end(),days[currDay]+7)-days.begin();
        int nIdx3=lower_bound(days.begin(),days.end(),days[currDay]+30)-days.begin();
        int op1=costs[0]+findMinPrice(days,nIdx1,costs,dp);
        int op2=costs[1]+findMinPrice(days,nIdx2,costs,dp);
        int op3=costs[2]+findMinPrice(days,nIdx3,costs,dp);
        return dp[currDay]=min({op1,op2,op3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        //at each day we have three options
        vector<int>dp(400,-1);
        return findMinPrice(days,0,costs,dp);
    }
};