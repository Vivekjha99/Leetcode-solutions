class Solution {
public:
    #define ll long long
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,long long>mp;
        for(auto v:rectangles){
            int a=v[0];
            int b=v[1];
            double d=(1.0*a/b);
            mp[d]++;
        }
        long long ans=0;
        for(auto it:mp){
            ll x=it.second;
            ans+=(x*(x-1))/2*1ll;
        }
        return ans;
    }
};