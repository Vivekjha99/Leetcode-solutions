class Solution {
public:
    int minAddToMakeValid(string s) {
       int a=0,b=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')a++;
            else b++;
            if(a<b){
                ans+=1;
                a=b;
            }              
        }
        ans+=abs(a-b);
        return ans;
    }
};