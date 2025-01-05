class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>pref(n+1,0);
        for(auto s:shifts){
            if(s[2]==0){
                pref[s[0]]--;
                pref[s[1]+1]++;
            }
            else{
                pref[s[0]]++;
                pref[s[1]+1]--;
            }
        }
        for(int i=1;i<=n;i++)pref[i]+=pref[i-1];
        for(int i=0;i<n;i++){
            //it can be negative as well
           int shift=(s[i]-'a'+pref[i])%26;
           shift=(shift+26)%26;
           //now place the shifted character directly
           s[i]='a'+shift;
        }
        return s;
    }
};