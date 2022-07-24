class Solution {
public:
    int arraySign(vector<int>& nums) {
        int p=1;
        for(auto x:nums){
            if(x<0)p*=-1;
            else if(x==0)p*=0;
            else p*=1;
        }
        return p;
    }
};