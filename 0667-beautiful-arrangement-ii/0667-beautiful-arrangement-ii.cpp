class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        if(k==1)return v;
        for(int i=1;i<k;i++){
            reverse(v.begin()+i,v.end());
        }
        return v;
    }
};