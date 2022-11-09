class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            for(auto x:nums[i]){
                v.push_back({x,i});
            }
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        vector<int>res(2);
        int j=0;
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++){
            int a=v[i].first;
            int b=v[i].second;
            mp[b]++;
            if(mp.size()==n){
                int d=a-v[j].first;
                if(ans>d){
                    res[0]=v[j].first;
                    res[1]=v[i].first;
                }
                ans=min(ans,d);
            }
            if(mp.size()==n){
                while(mp.size()==n){
                    // cout<<i<<" "<<j<<endl;
                    if(mp.size()==n){
                        int d1=a-v[j].first;
                        if(ans>d1){
                            res={v[j].first,a};
                        }
                        ans=min(ans,d1);
                    }
                    mp[v[j].second]--;
                    if(mp[v[j].second]==0)
                        mp.erase(v[j].second);
                    j++;
                }
            }
            
            
        }
        return res;
    }
};