class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>freq;
        if(s.size()==0)return 0;
        int n=s.size();
        int i=0;int ans=0;
        for(int j=0;j<n;j++){
            int x=s[j]-'a';
            freq[x]++;
            if(freq[x]>1){
                while(i<=j && freq[x]>1){
                    freq[s[i]-'a']--;
                    i++;
                }
            }
            // cout<<i<<" "<<j<<endl;
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};