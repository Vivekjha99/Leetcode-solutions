class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        //prefSum[i]->stores the total number of coins till coins[i-1]interval
        //shifted the index to i+1 so that i==0 condition is handled automatically
        vector<long long>prefixSum(n+1,0);
        vector<int>starts(n),ends(n);
        //calculating the prefix sum
        for(int i=0;i<n;i++){
            starts[i]=coins[i][0];
            ends[i]=coins[i][1];
            prefixSum[i+1]=prefixSum[i]+1LL*coins[i][2]*(coins[i][1]-coins[i][0]+1);
        }
        long long ans=0;
        //we will consider for first starting at starting index of an interval
        for(int i=0;i<n;i++){
            long long curr=0;
            //this is the ending of the window starting at s
            int s=coins[i][0],tar=s+k-1;
            int j=lower_bound(ends.begin(),ends.end(),tar)-ends.begin();
            //it can be possible that the window is partially present in the jth interval
            curr+=1LL*(prefixSum[j]-prefixSum[i]);//we are summing up till the j-1th interval
            //now it can be partial
            if(j<n)curr+=1LL*max(0,tar-coins[j][0]+1)*coins[j][2];
            //we have found the coins in the current window
            ans=max(ans,curr);
        }
        //now we will look for the windows which are closing at some interval
        for(int i=0;i<n;i++){
            long long curr=0;
            int e=coins[i][1],st=e-k+1;
            int j=lower_bound(starts.begin(),starts.end(),st)-starts.begin();
            curr+=1LL*(prefixSum[i+1]-prefixSum[j]);
            if(j>0){
                //now it may be partially present in an interval
                curr+=1LL*max(0,coins[j-1][1]-st+1)*coins[j-1][2];
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};