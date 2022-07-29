class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int c=t.size();int mlen=INT_MAX;
        int head=0,start=0,end=0;
       for(auto x:t)mp[x]++;
        while(end<s.size()){
           if(mp[s[end]]>0)c--;
            mp[s[end++]]--;
            while(c==0){
                if(end-start<mlen){
                    head=start;
                    mlen=end-start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0)c++;
                start++;  
            }
        }
        if(mlen==INT_MAX)return "";
        return s.substr(head,mlen);
    }
};