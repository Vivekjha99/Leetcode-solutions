class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n=s.size();
        vector<int>res;int inc=0,dec=n;
        for(int i=0;i<n;i++){
            if(s[i]=='I')res.push_back(inc++);
            if(s[i]=='D')res.push_back(dec--);
        }
        res.push_back(inc);
        return res;
    }
};