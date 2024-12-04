class Solution {
public:
    int minimumPushes(string word) {
        vector<pair<int,char>>v;
        vector<int>freq(26,0);
        for(auto ch:word){
            freq[ch-'a']++;
        }
        sort(freq.rbegin(),freq.rend());
        int btn=2;
        vector<int>freq1(10,0);
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)break;
            freq1[btn]++;
            ans+=freq1[btn]*freq[i];
            btn++;
            if(btn==10)btn=2;
        }
        return ans;
    }
};