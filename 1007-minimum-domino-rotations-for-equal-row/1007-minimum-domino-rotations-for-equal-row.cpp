class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int>freq1(7,0),freq2(7,0),same(7,0);
        int n=tops.size();
        for(int i=0;i<n;i++){
            freq1[tops[i]]++;
            freq2[bottoms[i]]++;
            if(tops[i]==bottoms[i])same[tops[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<7;i++){
            if(freq1[i]+freq2[i]-same[i]==n){
                ans=min(ans,n-max(freq1[i],freq2[i]));
            }
        }
        return ans==INT_MAX?-1:ans;
        
    }
};