class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>mp1,mp2;
        if(s1.size()>s2.size())return false;
            for(auto x:s1)mp1[x]++;
        for(int i=0;i<s1.size();i++)mp2[s2[i]]++;
        for(int i=s1.size();i<s2.size();i++){
            if(mp1==mp2)return true;
            mp2[s2[i-s1.size()]]--;
            if(mp2[s2[i-s1.size()]]==0)mp2.erase(s2[i-s1.size()]);
            mp2[s2[i]]+=1;
        }
        if(mp1==mp2)return true;
        return false;
    }
};