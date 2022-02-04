class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res=INT_MAX;
        int ans=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int x=nums[i];
            int start=i+1;
            int end=n-1;
            while(start<end){
                int sum=nums[i]+nums[start]+nums[end];
                if(sum>target)end--;
                else if(sum<target)start++;
                else return sum;
                if(res>abs(target-sum)){
                  ans=sum;
                    res=abs(target-sum);
                }
            }
        }
        return ans;
    }
};