class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>res(n,0);
        int ops=0,cnt=0;
        for(int i=0;i<n;i++){
            res[i]+=ops;
            cnt+=boxes[i]=='1'?1:0;
            ops+=cnt;
        }
        cnt=0;ops=0;
        for(int i=n-1;i>=0;i--){
            res[i]+=ops;
            cnt+=boxes[i]=='1'?1:0;
            ops+=cnt;
        }
        return res;
    }
};