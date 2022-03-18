class Solution {
public:
    string decode(string &s,int &i){
        string res;
        while(i<s.length() && s[i]!=']'){
            if(!isdigit(s[i])){
                res+=s[i++];
            }
            else{
                int x=0;
                while(i<s.length()  && isdigit(s[i])){
                    x=x*10+s[i++]-'0';
                }
                //for '['
                i++;
                string ns=decode(s,i);
                i++;//for ']'
                while(x-->0)res+=ns;
            }
        }
        return res;
    }
    string decodeString(string s) {
        int i=0;
       return decode(s,i);
    }
};