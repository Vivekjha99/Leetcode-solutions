class Solution {
public:
    bool check(vector<int>&nums,int op,int bagSize){
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            cnt+=nums[i]/bagSize;
            if(nums[i]%bagSize==0)cnt--;
        }
        return cnt<=op;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int st=1,en=nums.back();int ans=0;
        while(st<=en){
            int psize=st+(en-st)/2;
            if(check(nums,maxOperations,psize)){
                ans=psize;
                en=psize-1;
            }
            else
            st=psize+1;
        }
        return ans;
    }
};