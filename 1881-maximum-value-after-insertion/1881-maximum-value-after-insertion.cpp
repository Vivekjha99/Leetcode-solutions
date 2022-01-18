class Solution {
public:
    string maxValue(string s, int x) {
        int n=s.size();
        bool neg=false;
        if(s[0]=='-')neg=true;
        int i=0;
        if(neg)i=1;
        string res;
        int idx=-1;
      
        while(i<n){
            if(neg){
                int d=s[i]-'0';
                if(d>x){
                    idx=i;
                    break;
                }
            }
            else{
                int d=s[i]-'0';
                if(d<x){
                    idx=i;
                    break;
                }
            }
            i++;
        }
        if(idx==-1){
            res=s;
            res.push_back(x+'0');
            return res;
        }
        res=s.substr(0,idx);
        res.push_back(x+'0');
        res+=s.substr(idx,(n-idx));
        return res;
    }
};