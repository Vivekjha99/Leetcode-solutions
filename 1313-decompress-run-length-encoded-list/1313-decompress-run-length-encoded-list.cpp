class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>ans;
        for(int i=1;i<nums.size();i+=2){
            int f=nums[i-1];
            int e=nums[i];
            while(f--)ans.push_back(e);
        }
        return ans;
    }
};