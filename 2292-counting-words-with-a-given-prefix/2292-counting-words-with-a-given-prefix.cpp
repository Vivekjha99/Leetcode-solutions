class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int res=0;
        for(auto w:words){
            if(w.substr(0,pref.size())==pref)res++;
        }
        return res;
    }
};