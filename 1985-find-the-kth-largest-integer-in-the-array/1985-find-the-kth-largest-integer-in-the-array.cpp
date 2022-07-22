class Solution {
public:
    static bool cmp(const string &a,const string &b){
        if(a.size()==b.size()){
            return a<b;
        }
        else return a.size()<b.size();
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        int n=nums.size();
        return nums[n-k];
    }
};