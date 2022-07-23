class Solution {
public:
    void merge(vector<pair<int,int>>&v,vector<int>&cnt,int l,int mid,int r){
        vector<pair<int,int>>temp(r-l+1);
        int i=l,j=mid+1,k=0;
        while(i<=mid && j<=r){
            if(v[i].first<=v[j].first){
                temp[k++]=v[j++];
            }
            else{
                cnt[v[i].second]+=r-j+1;
                temp[k++]=v[i++];
            }
        }
        while(i<=mid)temp[k++]=v[i++];
        while(j<=r)temp[k++]=v[j++];
        for(int idx=l;idx<=r;idx++){
            v[idx]=temp[idx-l];
        }
    }
    void mergesort(vector<pair<int,int>>&v,vector<int>&cnt,int l,int r){
        if(l>=r)return;
        int mid=(l+r)/2;
        mergesort(v,cnt,l,mid);
        mergesort(v,cnt,mid+1,r);
        merge(v,cnt,l,mid,r);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        vector<int>cnt(n,0);
        mergesort(v,cnt,0,n-1);
        return cnt;
    }
};