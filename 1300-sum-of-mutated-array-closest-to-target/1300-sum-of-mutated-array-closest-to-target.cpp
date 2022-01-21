class Solution {
public:
    int sum(vector<int>&arr,int k){
        int res=0;
        for(auto x:arr){
            res+=x>k?k:x;
        }
        return res;
    }
    int findBestValue(vector<int>& arr, int target) {
        int res=0;
        for(auto x:arr)res+=x;
        sort(arr.begin(),arr.end());
        int l=1,r=arr.back();
        while(l<=r){
            int mid=l+(r-l)/2;
            int t=sum(arr,mid);
            if(t==target)return mid;
            if(t<target)l=mid+1;
            else r=mid-1;
        }
        int x1=sum(arr,l-1);
        int x2=sum(arr,l);
        if(abs(x1-target)<=abs(x2-target))return l-1;
        else return l;
    }
};