class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
       int n=nums.size();
        int st=0,en=n-1;
        long long ans=0;
        while(st<n-1 && nums[st]<nums[st+1])st++;
        while(en>0 && nums[en-1]<nums[en])en--;
        ans+=st+(long long)1;
        ans+=(n-en);
        //array is already sorted
        if(st>=en)
        return ((n)*(n+(long long)1))/(long long)2;
        int i=0,j=en;
        while(i<=st && j<n){
            if(nums[i]<nums[j]){
                ans+=(n-j);
                i++;
            }
            else
            j++;
        }
        return ans+(long long)1;

    }
};