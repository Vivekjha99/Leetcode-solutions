class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int res=0;
        sort(nums.begin(),nums.end());
        for(int i=0,lastAlloted=INT_MIN;i<nums.size();i++){
            int currMin=nums[i]-k;
            int currMax=nums[i]+k;
            if(lastAlloted<currMin){
                lastAlloted=currMin;
                res++;
            }
            else if(lastAlloted<currMax){
                lastAlloted=lastAlloted+1;
                res++;
            }
        }
        return res;
    }
};