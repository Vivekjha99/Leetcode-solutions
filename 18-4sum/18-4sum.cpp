class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>>res;
        if(n<=3)return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int t1=target-nums[i];
            for(int j=i+1;j<n;j++){
                int t2=t1-nums[j];
                int s=j+1;
                int e=n-1;
                while(s<e){
                    int sum=nums[s]+nums[e];
                    if(sum<t2)s++;
                    else if(sum>t2)e--;
                    else{
                        vector<int>v(4,0);
                        v[0]=nums[i];
                        v[1]=nums[j];
                        v[2]=nums[s];
                        v[3]=nums[e];
                        res.push_back(v);
                        while(s<e && v[2]==nums[s])s++;
                        while(s<e && v[3]==nums[e])e--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1])j++;
            }
            while(i+1<n &&nums[i]==nums[i+1])i++;
        }
        return res;
    }
};