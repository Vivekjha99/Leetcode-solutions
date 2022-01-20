class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int sz=quantities.size();
        int l=1,r=quantities[sz-1];
        while(l<=r){
            int mid=(l+r)/2;
            int res=0;
            for(auto x:quantities){
                res+=ceil(1.0*x/mid);
            }
            if(res>n)l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
};