class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int m=1e9+7;
        int n=arr.size();
        int ans=0;
        int e=0,o=0;
        if(arr[0]&1)o++;
        else e++;
        ans=o;
        for(int i=1;i<n;i++){
            arr[i]+=arr[i-1];
            if(arr[i]&1){
                ans=(ans+e+1)%m;
                o=(o+1)%m;
            }else{
                ans=(ans+o)%m;
                e=(e+1)%m;
            }
        }
        return ans%m;
    }
};