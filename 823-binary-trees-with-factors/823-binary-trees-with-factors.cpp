class Solution {
public:
    #define ll long long
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<ll,ll>mp;
        ll mod=1e9+7;
        int n=arr.size();
        sort(arr.begin(),arr.end());
        ll ans=0;
        for(int i=0;i<n;i++){
            ll cnt=1;
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j])continue;
                ll num1=arr[j];
                ll num2=arr[i]/arr[j];
                cnt=(cnt+(mp[num1]*mp[num2])%mod)%mod;
            }
            mp[arr[i]]=cnt;
            ans=(ans+cnt)%mod;
        }
        return ans;
        
    }
};