class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesser,same,greater;
        for(auto x:nums){
            if(x<pivot)lesser.push_back(x);
            else if(x==pivot)same.push_back(x);
            else greater.push_back(x);
        }
        lesser.insert(lesser.end(),same.begin(),same.end());
        lesser.insert(lesser.end(),greater.begin(),greater.end());
        return lesser;
    }
};