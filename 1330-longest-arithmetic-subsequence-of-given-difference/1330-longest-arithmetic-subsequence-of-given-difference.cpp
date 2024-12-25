class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int maxi=1;
        for(int i=0;i<n;i++){
            if(mp.find(arr[i]-diff)!=mp.end()){
                int len=mp[arr[i]-diff];
                maxi=max(maxi,len+1);
                mp[arr[i]]=len+1;
            }
            else{
                mp[arr[i]]=1;
            }
        }
        return maxi;
    }
};