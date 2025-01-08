class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(),tiles.end());
        int n=tiles.size();
        vector<int>starts(n),ends(n);
        vector<int>pref(n+1,0);
        for(int i=0;i<n;i++){
            starts[i]=tiles[i][0];
            ends[i]=tiles[i][1];
            pref[i+1]=pref[i]+(tiles[i][1]-tiles[i][0]+1);
        }
        //first we will check for carpet ending at a end interval
        long long ans=0;
        for(int i=0;i<n;i++){
            long long curr=0;
            int en=tiles[i][1];
            int st=en-carpetLen+1;
            int j=lower_bound(starts.begin(),starts.end(),st)-starts.begin();
            curr+=pref[i+1]-pref[j];
            if(j>0)curr+=max(0,tiles[j-1][1]-st+1);
            ans=max(ans,curr);
        }
        // starting at an interval
        for(int i=0;i<n;i++){
            long long curr=0;
            int st=tiles[i][0];
            int en=st+carpetLen-1;
            int j=lower_bound(ends.begin(),ends.end(),en)-ends.begin();
            curr+=pref[j]-pref[i];
            if(j<n)
                curr+=max(0,en-tiles[j][0]+1);
            ans=max(ans,curr);
        }
        return ans;

    }
};