class Solution {
public:
    int firstUniqChar(string s) {
        for(int i=0;i<s.size();i++){
            bool f=false;
            for(int j=0;j<s.size();j++){
                if(i!=j && s[i]==s[j]){
                    f=true;
                    break;
                }
            }
            if(f==false){
                return i;
            }
        }
        return -1;
    }
};