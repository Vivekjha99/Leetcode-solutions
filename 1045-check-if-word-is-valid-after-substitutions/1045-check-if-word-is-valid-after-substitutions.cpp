class Solution {
public:
    bool isValid(string s) {
        while(s.size()>0){
            int pos=s.find("abc");
            if(pos==-1 && s.size()>0)return false;
            string ns=s.substr(0,pos)+s.substr(pos+3);
            // cout<<ns<<endl;
            s=ns;    
        }
        return s.size()==0;
    }
};