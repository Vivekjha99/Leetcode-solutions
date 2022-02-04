class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>>res;
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k)pq.push({sum,{i,j}});
                else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{i,j}});
                }
                else {
                    break;
                    //as further j are greater
                }
            }
        }
        while(!pq.empty()){
            auto it=pq.top();
            res.push_back({nums1[it.second.first],nums2[it.second.second]});
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};