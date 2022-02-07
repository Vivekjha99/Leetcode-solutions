class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n=apples.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int idx=0;int ans=0;
        while(idx<n || pq.size()){
            if(idx<n && apples[idx]>0)pq.push({idx+days[idx]-1,apples[idx]});
            while(pq.size() && pq.top().first<idx)pq.pop();
            if(pq.size()){
                auto it=pq.top();
                pq.pop();
                ans++;
                if(it.second>1)
                pq.push({it.first,it.second-1});
            }
            idx++;
        }
        return ans;
    }
};