class Solution {
public:
    int helper(vector<int>&piles,int k){
        int n=piles.size();
        int ans=0;
        sort(piles.begin(),piles.end());
        int l=1,r=1e9;
       while(l<=r){
           int mid=(l+r)/2;
           int res=0;
               for(auto x:piles){
                   res+=ceil(1.0*x/mid);
               }
           if(res>k){
               l=mid+1;
           }
           else
               r=mid-1;
       }
        return l;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int ans=helper(piles,h);
        return ans;
    }
};