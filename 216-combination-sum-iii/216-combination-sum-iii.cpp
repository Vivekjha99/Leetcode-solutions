class Solution {
public:
    vector<int>nums={1,2,3,4,5,6,7,8,9};
    void solve(vector<vector<int>>&res,vector<int>&temp,int idx,int k,int n){
        if(k==temp.size()){
            if(n<0)return;
            if(n==0){
                res.push_back(temp);
                return;
            }
        }
        else if(k<temp.size())return;
        else{
            for(int i=idx;i<nums.size();i++){
                temp.push_back(nums[i]);
                solve(res,temp,i+1,k,n-nums[i]);
                temp.pop_back();
            }
        }   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        solve(res,temp,0,k,n);
        return res;
    }
};