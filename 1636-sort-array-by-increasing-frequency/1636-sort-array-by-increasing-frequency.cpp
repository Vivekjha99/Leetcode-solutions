class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(auto x:nums){
            freq[x]++;
        }
        sort(nums.begin(),nums.end(),[&](int x,int y){
            return freq[x]==freq[y]?x>y:freq[x]<freq[y];
        });
             return nums;
    }
};