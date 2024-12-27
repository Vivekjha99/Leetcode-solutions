class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        int maxTillNow=values[0];
        int res=0;
        for(int i=1;i<n;i++){
            int curr=values[i]-i;
           res=max(res,maxTillNow+curr);
           maxTillNow=max(maxTillNow,curr+2*i);
        }
        return res;
    }
};