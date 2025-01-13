class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        vector<int>freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int res=0;
        for(auto x:freq){
            if(x>2){
                if(x&1)res+=1;
                else res+=2;
            }
            else
            res+=x;
        }
        return res;
    }
};