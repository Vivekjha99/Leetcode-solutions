class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int>v(26,0);
        for(auto x:chars){
            v[x-'a']++;
        }
        int res=0;
        for(auto x:words){
            bool flag=true;
            vector<int>ch(26,0);
            for(auto y:x){
                if(++ch[y-'a']>v[y-'a']){
                    flag=false;
                    break;
                }
            }
            if(flag)res+=x.size();
        }
        return res;
    }
};