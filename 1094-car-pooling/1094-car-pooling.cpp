class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>stops(1001,0);
        for(auto x:trips){
            stops[x[1]]+=x[0];
            stops[x[2]]-=x[0];
        }
        for(auto x:stops){
            capacity-=x;
            if(capacity<0)return false;
        }
        return capacity>=0;
    }
};