class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,r=1e7;int ans=0;
        while(l<=r){
            //we are adding 1 because we want to have atleast 1 candy and not 0
            int mid=l+(r-l)/2;
            long long cnt=0;
            for(auto x:candies){
                cnt+=x/mid;
            }
            if(cnt>=k){
                ans=mid;
                l=mid+1;
            }
            else
            r=mid-1;
        }
        return ans;
    }
};