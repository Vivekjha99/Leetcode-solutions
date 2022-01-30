class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n;
        if(k==0)return;
        vector<int>res(n);
        for(int i=0;i<n;i++){
            res[(i+k)%n]=nums[i];
        }
        for(int i=0;i<n;i++)nums[i]=res[i];
    }
};