class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=1000005;
        while(l<r){
            int mid=(l+r)/2;
            int cnt=0;
            for(int i=0,j=0;i<n;i++){
                while(j<n && (nums[j]-nums[i])<=mid)j++;
                cnt+=j-i-1;
            }
            if(cnt<k)l=mid+1;
            else r=mid;
        }
        return l;
    }
};