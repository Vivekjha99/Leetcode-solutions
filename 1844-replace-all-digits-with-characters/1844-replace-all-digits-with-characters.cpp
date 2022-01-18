class Solution {
public:
    string replaceDigits(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            if(i&1){
                s[i]=(s[i]-'0'+s[i-1]-'a')%26+'a';
            }
        }
        return s;
    }
};