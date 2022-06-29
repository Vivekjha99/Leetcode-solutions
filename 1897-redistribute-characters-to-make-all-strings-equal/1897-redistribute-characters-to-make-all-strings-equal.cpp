class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);
        for(auto x:words){
            for(auto ch:x){
                freq[ch-'a']++;
            }
        }
        int n=words.size();
        for(int i=0;i<26;i++){
            if(freq[i]%n!=0)return false;
        }
        return true;
    }
};