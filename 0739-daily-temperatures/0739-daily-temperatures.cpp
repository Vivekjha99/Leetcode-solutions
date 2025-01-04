class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res(n,0);pq.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--){
            while(!pq.empty() && pq.top().first<=temperatures[i])pq.pop();
            if(!pq.empty() && pq.top().first>temperatures[i]){
                cout<<pq.top().first<<" "<<i<<endl;
                res[i]=pq.top().second-i;
            }
            pq.push({temperatures[i],i});
        }
        return res;
    }
};