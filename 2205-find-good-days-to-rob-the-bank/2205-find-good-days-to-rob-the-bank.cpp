class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& sec, int time) {
        int n=sec.size();
        vector<int>pref(n,0),suff(n,0);
        for(int i=1;i<n;i++){
            if(sec[i]<=sec[i-1])pref[i]+=pref[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(sec[i+1]>=sec[i])suff[i]+=suff[i+1]+1;
        }
        vector<int>res;
        for(int i=time;i<n;i++){
            if(pref[i]>=time && suff[i]>=time)res.push_back(i);
        }
        return res;
    }
};