class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq1(26,0),freq2(26,0);
        for(auto x:s){
            freq1[x-'a']++;
        }
        for(auto x:t)freq2[x-'a']++;
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i])return false;
        }
        return true;
    }
};