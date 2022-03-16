class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int n=s.size();
        int len=sw.size();
        int cnt=0;
        string ns="";
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                cnt++;
                ns="";
            }
            else ns+=s[i];
            if(ns==sw){
                return cnt+1;
            }
        }
        if(ns==sw)return cnt+1;
        return -1;
    }
};