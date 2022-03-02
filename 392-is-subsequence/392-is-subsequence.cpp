class Solution {
public:
    bool isSubsequence(string t, string s) {
        int i=0,j=0;
        int n1=s.length();
        int n2=t.length();
        for(int i=0;i<n1;i++){
            if(s[i]==t[j]){
                j++;
            }
            if(j==n2)return true;
        }
        return j==n2;
    }
};