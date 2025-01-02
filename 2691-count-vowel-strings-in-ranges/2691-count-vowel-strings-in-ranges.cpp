class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<long long> vs(words.size(), 0ll);
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            if (isVowel(s[0]) && isVowel(s.back())) {
                vs[i] = 1ll ;
            } 
            if(i!=0) vs[i]+=vs[i - 1];
        }
        vector<int> res;
        for (auto q : queries) {
            long long r = vs[q[1]];
            if(q[0]>0)r-=vs[q[0]-1];
            res.push_back((int)r);
        }
        return res;
    }
};