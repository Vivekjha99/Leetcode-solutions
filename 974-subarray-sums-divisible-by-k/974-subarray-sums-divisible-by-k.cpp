class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt=0;
            for(int i=0;i<nums.size();i++){
                sum=k?(sum+nums[i]+k)%k:sum+nums[i];
                if(sum<0)sum=(sum+k)%k;
                // cout<<sum<<" ";
                cnt+=mp[sum];
                mp[sum]++;
            }
        return cnt;
    }
};