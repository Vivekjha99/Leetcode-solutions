class Solution {
public:
    bool check(vector<int>&nums,int force,int m){
        int cnt=1;
        int prev=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=nums[prev]+force){
                prev=i;
                cnt++;
            }
            if(cnt==m)return true;
        }
        if(cnt<m)return false;
        return true;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position[position.size()-1];
        int l=1,r=n;int ans=0;
        while(l<=r){
            int mid=(l+r)/2;
            if(check(position,mid,m)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};