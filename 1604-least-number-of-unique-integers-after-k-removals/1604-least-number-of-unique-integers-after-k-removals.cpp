class comp {
    public:
       bool operator()(pair<int,int>&a, pair<int,int>&b){
           if(a.second>b.second){
               return true;
           }
           return false;
      }
};
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int>mp;
        for(auto x:arr){
            mp[x]++;
        }
        vector<pair<int,int>>v;
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp>pq;
        for(auto [x,f]:mp){
            pq.emplace(x,f);
        }
        while(k>0 && !pq.empty()) {
           k--;
            pair<int,int> p=pq.top();
            pq.pop();
            if(p.second==1)continue;
            else pq.push({p.first,p.second-1});
            
        }
        return pq.size();
        
    }
};