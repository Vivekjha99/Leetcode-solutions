class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       int n=nums.size();
       long long res=1ll*k*(k+1)/2;int cnt=0;
       int ele=k+1;
       sort(nums.begin(),nums.end());
       for(int i=0;i<n;i++){
        while(i>0 && i<n &&   nums[i]==nums[i-1])i++;
        if(i>=n)break;
        if(nums[i]<=ele){
            cout<<nums[i]<<" ";
            res-=nums[i];
            res+=ele++;
        }
       } 
       return res;
    }
};