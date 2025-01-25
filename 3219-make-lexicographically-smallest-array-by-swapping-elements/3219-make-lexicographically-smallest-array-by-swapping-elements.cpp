class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       int n=nums.size();
       vector<pair<int,int>>arr;
       for(int i=0;i<n;i++)arr.push_back({nums[i],i});
       sort(arr.begin(),arr.end(),[&](pair<int,int>&a, pair<int,int>&b){
        return a.first<b.first;
       });
       vector<vector<pair<int,int>>>pairs;
       pairs.push_back({arr[0]});
       for(int i=1;i<n;i++){
        if(arr[i].first-arr[i-1].first<=limit){
            pairs.back().push_back(arr[i]);
        }
        else
            pairs.push_back({arr[i]});
       }
       for(auto v:pairs){
        vector<int>indices;
        for(auto p:v){
            indices.push_back(p.second);
        }
        sort(indices.begin(),indices.end());
        //sorting the values of each sub array
        for(int i=0;i<indices.size();i++){
            nums[indices[i]]=v[i].first;
        }
       }
       return nums;

    }
};