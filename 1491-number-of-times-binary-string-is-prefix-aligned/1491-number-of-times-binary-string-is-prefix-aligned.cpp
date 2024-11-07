class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int lMax=0;int ans=0;
        for(int i=0;i<flips.size();i++){
            lMax=max(lMax,flips[i]);
            if(lMax==i+1)ans++;
        }
        return ans;
    }
};