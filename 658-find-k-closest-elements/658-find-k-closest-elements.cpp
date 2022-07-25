class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int n=arr.size();
        for(int i=0;i<n;i++){
            pq.push({abs(x-arr[i]),arr[i]});
        }
        vector<int>ans(k);
        int idx=0;
        while(!pq.empty() && idx!=k){
            ans[idx++]=pq.top().second;
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};