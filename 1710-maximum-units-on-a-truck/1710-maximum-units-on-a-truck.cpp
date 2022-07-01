class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n=boxTypes.size();
        priority_queue<pair<int,int>>pq;
        for(auto x:boxTypes){
            pq.push({x[1],x[0]});
        }
        int ans=0;
        while(truckSize>0 && !pq.empty()){
            auto it=pq.top();
            int units=it.second;
            int sz=it.first;
          // cout<<"truckSize= "<<truckSize<<endl;
            if(truckSize>units){
                ans+=units*sz;
                truckSize-=units;
            }
            else{
                ans+=sz*truckSize;
                truckSize=0;
            }
              // cout<<units<<" "<<sz<<" "<<truckSize<<" "<<ans<<endl;
            pq.pop();
        }
        return ans;
    }
};