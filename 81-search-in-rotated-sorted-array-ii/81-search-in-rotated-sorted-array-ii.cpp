class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0,e=n-1;
        int ans=-1;
        while(s<=e){
            //removing duplicates
            while(s<e && nums[s]==nums[s+1])s++;
            while(s<e && nums[e]==nums[e-1])e--;
            int mid=(s+e)>>1;
            if(nums[mid]==target){
                ans=mid;
                break;
            }
            else if(nums[mid]>=nums[s]){
                if(target<=nums[mid] && target>=nums[s]){
                    e=mid-1;
                }
                else 
                    s=mid+1;
            }
            else{
                if(nums[mid]<=target && nums[e]>=target)
                    s=mid+1;
                else 
                    e=mid-1;
            }
        }
        return ans==-1?false:true;
    }
};