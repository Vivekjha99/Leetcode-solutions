class Solution {
public:
bool isValid(vector<int>q,int n,int val,long long t){
    int idx=0;
    for(int i=0;i<n && idx<q.size();i++){
        if(q[idx]-val>0){
            q[idx]-=val;
            t-=val;
        }
        else{
            t-=q[idx];
            q[idx++]=0;
        }
    }
    cout<<t<<endl;
    return t==0;
}
    int minimizedMaximum(int n, vector<int>& q) {
        int maxi=0;
       long long total=0;
        for(auto x:q){
            total+=x;
            maxi=max(maxi,x);
        }
        int ans=0;
        int low=(total)/n;
        while(low<=maxi){
            int mid=low+(maxi-low)/2;
            cout<<mid<<endl;
            if(isValid(q,n,mid,total)){
                maxi=mid-1;
                ans=mid;
            }
            else
            low=mid+1;
        }
        return ans;
    }
};