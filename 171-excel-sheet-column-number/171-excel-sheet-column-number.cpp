class Solution {
public:
    int titleToNumber(string s){
        int n=s.size();
        int res=0;
        if(n==1){
            return (s[0]-'A'+1);
        }
        for(int i=0;i<n-1;i++){
            int x=s[i]-'A'+1;
            res+=x;
            res*=26;
        }
        res+=s[n-1]-'A'+1;
        return res;  
    }
};