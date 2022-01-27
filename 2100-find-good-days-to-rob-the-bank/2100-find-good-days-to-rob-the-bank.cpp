class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        int n=nums.size();
        if(n<time)return {};
        if(time==0){
            vector<int>res;
            for(int i=0;i<n;i++)res.push_back(i);
            return res;
        }
        vector<int>inc(n,1),dec(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1])dec[i]=1+dec[i-1];
            if(nums[i]>=nums[i-1])inc[i]=1+inc[i-1];
        }
        vector<int>ans;
        for(int i=time;i<n-time;i++){
            if((dec[i]-dec[i-time])>=time && (inc[i+time]-inc[i])>=time)ans.push_back(i);
        }
        return ans;
    }
};