class Solution {
public:
    vector<int> countBits(int n) {
        int mask=1;
        int cnt=0;
        vector<int>ans(n+1);
        for(int i=0;i<=n;i++){
            int x=i;
            cnt=0;
        while(x>0){
            if(x&1)
                cnt++;
            x=x>>1;
        }
            ans[i]=cnt;
        }
        return ans;
    }
};