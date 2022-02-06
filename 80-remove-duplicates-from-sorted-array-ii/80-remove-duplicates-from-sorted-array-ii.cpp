class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;int curr=1;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                curr++;
                if(curr<=2)
                    nums[i-cnt]=nums[i];
                    
                if(curr>2)cnt++;
            }
            else{
                curr=1;
                nums[i-cnt]=nums[i];
            }
        }
        return n-cnt;
    }
};